const fs = require('fs')
const path = require('path')
const https = require('https')
const { libcoreVersion } = require('./package.json')

const perPlatform = {
  linux: {
    dir: 'linux',
    files: ['libledger-core.so'],
    chmod: 0o755,
  },
  darwin: {
    dir: 'macos',
    files: ['libledger-core.dylib'],
    chmod: 0o755,
  },
  win32: {
    dir: 'win/vs2017',
    files: ['ledger-core.dll', 'ledger-core.lib', 'crypto.dll'],
  },
}

const conf = perPlatform[process.platform]
if (!conf) {
  console.error(`Platform ${process.platform} is not supported`)
  process.exit(1)
}

const dir = conf.dir
// const dir =
//   process.platform === 'linux' && Number(process.version.match(/^v(\d+\.\d+)/)[1]) >= 10
//     ? `${conf.dir}-arch_ssl_1_1`
//     : conf.dir

const endpointURL = `https://s3-eu-west-1.amazonaws.com/ledger-lib-ledger-core/${libcoreVersion}/${dir}`

if (!fs.existsSync('lib')) {
  fs.mkdirSync('lib')
}

conf.files.reduce(
  (p, file) =>
    p.then(() =>
      get(file)
        .then(() => {
          if (conf.chmod) {
            fs.chmodSync(`lib/${file}`, conf.chmod)
          }
        })
        .catch(err => {
          console.error(`Error: ${err.message}, statusCode: ${err.code}`)
          process.exit(1)
        }),
    ),
  Promise.resolve(),
)

function get(file) {
  return new Promise((resolve, reject) => {
    const dest = `lib/${file}`
    if (process.env.LEDGER_CORE_LOCAL_BUILD) {
      const src = path.join(process.env.LEDGER_CORE_LOCAL_BUILD, file)
      console.log(`Copy ${src} -> ${dest}`)
      fs.copyFile(src, dest, err => {
        if (err) reject(err)
        else resolve()
      })
    } else {
      const url = `${endpointURL}/${file}`
      console.log(`Downloading ${url} ...`)
      const f = fs.createWriteStream(dest)
      f.on('finish', () => {
        console.log(`${file} downloaded.`)
        f.close(resolve)
      })

      https
        .get(url, res => {
          if (res.statusCode === 404) {
            reject({ code: res.statusCode, message: res.statusMessage })
          } else {
            res.pipe(f)
          }
        })
        .on('error', err => {
          fs.unlink(dest)
          reject(err)
        })
    }
  })
}
