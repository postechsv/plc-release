import os
from stappMaker import StappFileMaker
import sys

def findMainProjectFolder(projectLoc):
    try:
        if "appli.k5p" in os.listdir(projectLoc):
            return projectLoc
        else:
            for fileOrDir in os.listdir(projectLoc):
                absPathofFile = os.path.abspath(projectLoc + "/" + fileOrDir)
                if os.path.isdir(absPathofFile) and "appli.k5p" in os.listdir(absPathofFile): return absPathofFile
    except FileNotFoundError:
        print("Location of Straton project folder is not correct")
        print("There is no", projectLoc)
        exit()

    print("Location of Straton project folder is not correct")
    print("There is no 'appli.k5p' file! ")
    exit()


fullPathofProjectFile = findMainProjectFolder(os.path.abspath(str(sys.argv[1])))
projectName = os.path.abspath(fullPathofProjectFile).split("/")[-1]
workingDir = os.path.abspath(str(sys.argv[0]))


stappContent = StappFileMaker(workingDir, fullPathofProjectFile)
stappFilePath = os.path.dirname(fullPathofProjectFile) + "/" + projectName + ".st"
stappWriter = open(stappFilePath, 'w')
stappWriter.write(stappContent.makeStapp())
stappWriter.close()

print(stappFilePath)
