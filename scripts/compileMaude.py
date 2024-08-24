import sys
import os
import csv
import reqTranslator
import csvTranslator
from mainFrontEnd import MAINTRANSLATOR
import time

def analyzePLC(maudeFile):
    try:
        testOut = os.popen("echo 'q' | " + os.environ['MAUDE_BIN'] + "/maude-se-yices2 " + maudeFile).read()

    except:
        print("Maude Error Ocurred")
        print("Please check " , maudeFile)
        exit()

    return testOut


def makeFileToAnalyze(fullPathOfMaudeFile):
    return fullPathOfMaudeFile

startTime = time.time()
fullPathofProjectFile = os.path.abspath(str(sys.argv[1]))

projectName = os.path.abspath(fullPathofProjectFile).split("/")[-1].split(".st")[0]

if len(sys.argv) > 3:
    fullPathOfMaudeFile = MAINTRANSLATOR(fullPathofProjectFile, "symbolic", projectName).returnMaudeFilePath()
else:
    fullPathOfMaudeFile = MAINTRANSLATOR(fullPathofProjectFile, "symbolic", projectName, False).returnMaudeFilePath()




print("compiling " + projectName)

nameOFanalysisFile = makeFileToAnalyze(fullPathOfMaudeFile)

