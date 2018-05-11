import urllib
import os

bucketURL = "https://s3-eu-west-1.amazonaws.com/ledger-lib-ledger-core/libledger-core.so"
libFile = "lib/libledger-core.so"

opener = urllib.URLopener()

print('Downloading ' + bucketURL + ' ...')
opener.retrieve(bucketURL, libFile)
os.chmod(libFile, 755)
