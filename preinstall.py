import platform
import urllib
import os

baseURL = "https://s3-eu-west-1.amazonaws.com/ledger-lib-ledger-core"
userPlatform = platform.system()

bucketFile = ""
if userPlatform == "Linux":
    bucketFile = "libledger-core.so"
elif userPlatform == "Darwin":
    bucketFile = "libledger-core.dylib"
elif userPlatform == "Windows":
    bucketFile = "libledger-core.dll"
else:
    raise Exception('Unsupported platform ' + userPlatform)

opener = urllib.URLopener()

endpointURL = baseURL + "/" + bucketFile
finalFile = "lib/" + bucketFile

print('Downloading ' + endpointURL + '...')
opener.retrieve(endpointURL, finalFile)
os.chmod(finalFile, 0755)
