import sys
import os
import csv
import reqTranslator
import csvTranslator
from mainFrontEnd import MAINTRANSLATOR
import time

def analyzePLC(maudeFile):
    try:
        testOut = os.popen("echo 'q' | maude-se-yices2 " + maudeFile).read()

    except:
        print("Maude Error Ocurred")
        print("Please check " , maudeFile)
        exit()

    return testOut

def checkWhetherFailorNot(testOut, STEPSIZE, maudeFile, projectName, reqName):
    with open(os.path.dirname(maudeFile) + "/" + projectName + "-" + reqName + '.log', 'w') as logFile:
        logFile.write(testOut)

    logfilePath = os.path.dirname(maudeFile) + "/" + projectName + "-" + reqName + '.log'

    csvFile = open(os.path.dirname(maudeFile) + "/" + projectName + "-" + reqName + "-result" + '.csv', 'w', newline='')

    csvWr = csv.writer(csvFile)
    csvWr.writerow(['ProjectName', projectName])
    csvWr.writerow(['RequirementFile', reqName])

    if ("No solution." in testOut):
        csvWr.writerow(['Result', "test succeeded"])
        csvWr.writerow([" "])
        print ("test succeeded")

    elif ("Solution" in testOut):
        csvWr.writerow(['Result', "test failed"])
        csvWr.writerow([" "])
        print("test failed")

        csvDataExtractor = csvTranslator.CSVTranslator(logfilePath, STEPSIZE)
        csvInputResult, csvOutputResult, maxLength = csvDataExtractor.results()

        csvWr.writerow([" - ", " - ", "Step"])
        csvWr.writerow(["VarName", "VarType"] + [i for i in range(maxLength)])
        for varName in csvInputResult.keys():
            listOfsteps = list()
            for ith, singleVal in enumerate(csvInputResult[varName]):
                listOfsteps.append(singleVal)
            csvWr.writerow([varName, "IN"] + listOfsteps)

        for varName in csvOutputResult.keys():
            listOfsteps = list()
            for ith, singleVal in enumerate(csvOutputResult[varName]):
                listOfsteps.append(singleVal)
            csvWr.writerow([varName, "OUT"] + listOfsteps)
    else:
        csvWr.writerow(['Result', "run time error \nPlease check req file"])
        print("run time error")
        print("Please check req file")

    csvFile.close()


def makeFileToAnalyze(fullPathOfMaudeFile, searchFormat):
    with open(fullPathOfMaudeFile, 'a') as searchFile:
        searchFile.write(searchFormat)
    return fullPathOfMaudeFile

startTime = time.time()
fullPathofProjectFile = os.path.abspath(str(sys.argv[1]))

projectName = os.path.abspath(fullPathofProjectFile).split("/")[-1].split(".st")[0]
reqName = os.path.abspath(str(sys.argv[2])).split("/")[-1].split(".req")[0]

fullPathOfVerifFile = os.path.abspath(str(sys.argv[2]))

searchCommandTranslator = reqTranslator.ReqFileTranslator(fullPathOfVerifFile)
searchFormat, symbolicOrconcrete, STEPSIZE = searchCommandTranslator.results()

if len(sys.argv) > 3:
    fullPathOfMaudeFile = MAINTRANSLATOR(fullPathofProjectFile, symbolicOrconcrete, projectName, reqName).returnMaudeFilePath()
else:
    fullPathOfMaudeFile = MAINTRANSLATOR(fullPathofProjectFile, symbolicOrconcrete, projectName, reqName, False).returnMaudeFilePath()



"""
try:
    fullPathOfMaudeFile = MAINTRANSLATOR(fullPathofProjectFile, symbolicOrconcrete, projectName, reqName).returnMaudeFilePath()
except:
    print("Serious Error occured during compile")
    exit()
"""



print("analyzing " + projectName + " using " + reqName )

nameOFanalysisFile = makeFileToAnalyze(fullPathOfMaudeFile, searchFormat)
testOutput = analyzePLC(nameOFanalysisFile)
checkWhetherFailorNot(testOutput, STEPSIZE, fullPathOfMaudeFile, projectName, reqName)

print("Result will be located in ", os.path.dirname(fullPathOfMaudeFile))

print("running time : ", time.time() - startTime, "sec")
