import platform
import urllib
import os
import sys
import shutil

libCoreVersion = "2.5.0-rc"

baseURL = "https://s3-eu-west-1.amazonaws.com/ledger-lib-ledger-core"
filePath = ""

userPlatform = platform.system()

bucketFile = ""
if userPlatform == "Linux":
    filePath = libCoreVersion + "/linux"
    bucketFile = "libledger-core.so"
elif userPlatform == "Darwin":
    filePath = libCoreVersion + "/macos"
    bucketFile = "libledger-core.dylib"
elif userPlatform == "Windows":
    filePath = libCoreVersion + "/win/vs2015"
    bucketFile = "ledger-core.dll"
else:
    raise Exception('Unsupported platform ' + userPlatform)

opener = urllib.URLopener()

endpointURL = baseURL + "/" + filePath
finalFile = "lib/" + bucketFile

if not os.path.exists("lib"):
    os.makedirs("lib")

local_build = os.environ.get('LEDGER_CORE_LOCAL_BUILD', None)

if local_build:
    print('Copying ' + local_build)
    shutil.copyfile(local_build, finalFile)
    sys.exit(0)

print('Downloading ' + endpointURL + "/" + bucketFile + ' ...')
opener.retrieve(endpointURL + "/" + bucketFile, finalFile)

if userPlatform == "Windows":
    print('Downloading ' + endpointURL + "/ledger-core.lib" + ' ...')
    opener.retrieve(endpointURL + "/ledger-core.lib", "lib/ledger-core.lib")
    print('Downloading ' + endpointURL + "/crypto.dll" + ' ...')
    opener.retrieve(endpointURL + "/crypto.dll", "lib/crypto.dll")

if userPlatform != "Windows":
    os.chmod(finalFile, 0o755)
