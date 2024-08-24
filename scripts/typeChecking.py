from typeChecker import typeCheck
from libMaker import libDBmaker
from antlr4 import *
from gen.STLexer import STLexer
from gen.STParser import STParser
from copy import deepcopy
from dataFormat import totalEnv

class typeChecker:
    def __init__(self, libFBdb):
        self.visitor = typeCheck(libFBdb)

    def startTypeCheck(self, stappFile):
        input_stream = FileStream(stappFile)
        lexer = STLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = STParser(tokens)
        tree = parser.stapp()
        self.visitor.visit(tree)

    def returnFBtypes(self):
        return deepcopy(self.visitor.FBEnvDict)

    def returnTotalEnv(self):
        totalEnvInstance = totalEnv()
        totalEnvInstance.setFBs(self.visitor.programs, self.visitor.subprograms, self.visitor.udfbs + list(self.visitor.libBackup.keys()), self.visitor.structures)
        totalEnvInstance.setGlobal(self.visitor.globalVarEnv)
        totalEnvInstance.setTypes(self.visitor.enumDict, self.visitor.bitDict)
        totalEnvInstance.setFBenv(self.visitor.FBEnvDict)
        totalEnvInstance.setCycleTime(self.visitor.cycleTime)

        return deepcopy(totalEnvInstance)

    def returnSwitch(self): return self.visitor.switch


"""
libFB = libDBmaker().makeBuiltINLibTypeFile("./libs")

typecheckerInstance = typeChecker(libFB)
typecheckerInstance.startTypeCheck("./MA-example1.st")


typecheckerInstance = typeChecker(libFB)
typecheckerInstance.startTypeCheck("pms.txt")


for FB in typecheckerInstance.returnFBtypes():
    print("================")
    print(FB)
    print(typecheckerInstance.returnFBtypes()[FB].type)
    print("||||||||||||||||||||")
"""

