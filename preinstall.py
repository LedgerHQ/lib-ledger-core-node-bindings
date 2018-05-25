import platform
import urllib
import os

baseURL = "https://s3-eu-west-1.amazonaws.com/ledger-lib-ledger-core"
filePath = ""

userPlatform = platform.system()

bucketFile = ""
if userPlatform == "Linux":
    filePath = "latest/linux"
    bucketFile = "libledger-core.so"
elif userPlatform == "Darwin":
    filePath = "latest/macos"
    bucketFile = "libledger-core.dylib"
elif userPlatform == "Windows":
    bucketFile = "libledger-core.dll"
else:
    raise Exception('Unsupported platform ' + userPlatform)

opener = urllib.URLopener()

endpointURL = baseURL + "/" + filePath + "/" + bucketFile
finalFile = "lib/" + bucketFile

if not os.path.exists("lib"):
    os.makedirs("lib")

print('Downloading ' + endpointURL + ' ...')
opener.retrieve(endpointURL, finalFile

if userPlatform != "Linux":
    os.chmod(finalFile, 0755)
