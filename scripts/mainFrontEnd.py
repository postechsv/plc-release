import os
from stTranslating import stTranslator
from typeChecking import typeChecker
from libMaker import libDBmaker
from stappMaker import StappFileMaker
import sys


def returnAfterMergingWithAppFormat(loadFormat, content):
    return loadFormat + " \n\n" + "mod APP is \n" \
            + "inc PLC-CORE .\n"  \
            + "inc PLC-LIB .\n" \
            + "op PROJECTFILE : -> StratonProject .\n" \
            + "eq PROJECTFILE =\n" \
            + "(\n" + content + "\n) .\n" \
                                     + "  op LINKEDFILE : -> StratonProject .\n" \
                                     + "  eq LINKEDFILE = PROJECTFILE <-load- LIB .\n" \
                                     + "  op APP : -> KConfig .\n" \
                                     + "  eq APP = [[[ LINKEDFILE ]]] .\n" \
                                     + "endm\n"

class MAINTRANSLATOR:
    def __init__(self, projectPath, concretORsymbolic, projectName, reqName, complete=True):
        self.returnMaudeFile = ""
        self.workingDir = os.path.abspath(str(sys.argv[0]))
        self.switch = True

        print("Compiling " + projectPath.split("/")[-1] + " ... ")

        if (concretORsymbolic != "concrete" and concretORsymbolic != "symbolic"):
            print("Compile Failed")
            print("Wrong Option")
            print("is 'symbolic' option that you want?")
            exit()

        self.runType = concretORsymbolic
        self.projectPath = projectPath

        libDBmakerInstance = libDBmaker()
        libFB = libDBmakerInstance.makeBuiltINLibTypeFile(os.path.dirname(self.workingDir) + "/../libs")
        libMaudeFilePath = libDBmakerInstance.makeLibMaudeFile(complete)

        typecheckerInstance = typeChecker(libFB)
        typecheckerInstance.startTypeCheck(projectPath)
        self.switch = typecheckerInstance.returnSwitch()


        if self.switch:
            stTranslatorInstance = stTranslator(projectPath, typecheckerInstance.returnTotalEnv())
            self.switch = stTranslatorInstance.returnSwitch()
        else:
            print("Compile Failed")
            exit()

        if self.switch:
            fileWriter = open(os.path.dirname(projectPath) + "/" + projectName + "-" + reqName + ".maude", "w")
            loadFormat = ""
            if concretORsymbolic == "concrete":
                loadFormat += "load " + os.path.dirname(self.workingDir) + "/../semantics/interpreter/merge \n"
            else:
                loadFormat += "load " + os.path.dirname(self.workingDir) + "/../semantics/interpreter/merge \n"
            loadFormat += "load " + libMaudeFilePath + "\n"

            preprocessed = returnAfterMergingWithAppFormat(loadFormat, stTranslatorInstance.returnMaude(libFB))
            fileWriter.write(preprocessed)
            fileWriter.close()
            print("Compile Succeeded")
            self.returnMaudeFile = os.path.dirname(projectPath) + "/" + projectName + "-" + reqName + ".maude"
        else:
            print("Compile Failed")
            exit()

    def returnMaudeFilePath(self): return self.returnMaudeFile

"""
MAINTRANSLATOR("./MA", "symbolic", "MA", "example1")
MAINTRANSLATOR("./PMSEmulator", "symbolic", "PMS", "example1")
"""
