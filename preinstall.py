import platform
import urllib
import os

baseURL = "https://s3-eu-west-1.amazonaws.com/ledger-lib-ledger-core"
userPlatform = platform.system()

bucketFile = "libledger-core.so"
if userPlatform == "Darwin":
    bucketFile = "libledger-core.dylib"
else if userPlatform == "Windows":
    bucketFile = "libledger-core.dll"

opener = urllib.URLopener()

print('Downloading ' + bucketURL + ' ...')
opener.retrieve(baseURL + "/" + bucketURL, "lib/" + libFile)
os.chmod(libFile, 0755)
