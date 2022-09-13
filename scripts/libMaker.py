from typeChecker import typeCheck
from stTranslator import stTranslate
from antlr4 import *
from gen.STLexer import STLexer
from gen.STParser import STParser
from gen.DCLVisitor import DCLVisitor
import os
from copy import deepcopy

from dataFormat import VarFormat
from dataFormat import totalEnv

def libMaudeFormat(name, content):
    return "fmod " + name + " is\n" \
    + "  inc POU-DEF . \n" \
    + "  inc DATA-CONVERSION .\n" \
    + "  inc PLC-PRIMITIVES .\n" \
    + "  inc TIMER-SEMANTICS .\n" \
    + "  op " + name.replace("_", "") + " : -> [POUDefinition] . \n" \
    + "  eq " + name.replace("_", "") + " = \n" \
    + "(\n" + content + "\n ) .\n" + "endfm\n\n"


def maudeLibImportFormat(libList):
    default = "fmod PLC-LIB is\n  inc LIST{POUDefinition} .\n  op LIB : -> List{POUDefinition} .\n"
    for ith, lib in enumerate(libList):
        default += "  inc " + lib + " .\n"
        libList[ith] = libList[ith].replace("_", "")
    default += "  eq LIB = " + " ".join(libList) + " .\n"
    default += "endfm\n\n"
    return default


class libDBmaker:
    def __init__(self):
        self.visitorType = typeCheck(dict())
        self.libDirectory = ""
        self.totalFBEnv = totalEnv()


    def extractTypeData(self, libFile):
        input_stream = FileStream(libFile)
        lexer = STLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = STParser(tokens)
        tree = parser.udfbs()
        name, ctx = self.visitorType.visit(tree)
        self.visitorType.nowPou = name
        self.visitorType.visit(ctx)
        return self.visitorType.FBEnvDict

    def makeBuiltINLibTypeFile(self, libDirectory):
        self.libDirectory = libDirectory
        stlibs = libDirectory + "/library.stlib"
        listlibs = open(stlibs, "r").read().split("\n")
        libFBEnv = dict()

        for aLib in listlibs:
            libFBEnv.update(deepcopy(self.extractTypeData(libDirectory + "/" + aLib + ".st")))

        self.totalFBEnv.setFBenv(deepcopy(libFBEnv))
        return libFBEnv

    def makeLibMaudeFile(self, libCompleteSwitch):
        if libCompleteSwitch:
            listlibs = open(self.libDirectory + "/library.stlib", "r").read().split("\n")
            libResult = ""
            for aLib in listlibs:
                self.makeLibMaudeCode(self.libDirectory + "/" + aLib + ".st")
                libResult += libMaudeFormat(aLib, self.totalFBEnv.FBEnvDict[aLib].returnMaude())
            libFile = open(self.libDirectory + "/libcollection.maude", "w")
            libFile.write(libResult + maudeLibImportFormat(listlibs))

            libFile.close()
        return self.libDirectory + "/libcollection.maude"

    def makeLibMaudeCode(self, libFile):
        visitor = stTranslate(self.totalFBEnv)
        input_stream = FileStream(libFile)
        lexer = STLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = STParser(tokens)
        tree = parser.udfbs()
        name, ctx = visitor.visit(tree)
        visitor.nowPou = name
        visitor.visit(ctx)
        self.totalFBEnv.FBEnvDict =deepcopy(visitor.FBEnv)
        return

"""
libInstance = libDBmaker()
libFB = libInstance.makeBuiltINLibTypeFile("./libs")
libMaude = libInstance.makeLibMaudeFile(True)
print(libInstance.visitorType.FBEnvDict.keys())
print(libInstance.visitorType.FBEnvDict['PLS'].varEnv.keys())
"""





