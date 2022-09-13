from stTranslator import stTranslate
from libMaker import libDBmaker
from antlr4 import *
from gen.STLexer import STLexer
from gen.STParser import STParser
from typeChecking import typeChecker

class stTranslator:
    def __init__(self, stappFile, totalEnv):
        self.totalEnv = totalEnv
        self.visitor = stTranslate(totalEnv)

        input_stream = FileStream(stappFile)
        lexer = STLexer(input_stream)
        tokens = CommonTokenStream(lexer)
        parser = STParser(tokens)
        tree = parser.stapp()
        self.visitor.visit(tree)


    def returnMaude(self, libFB):
        self.updateFB()
        programInformation = self.visitor.programListMaude
        programInformation =  programInformation
        return "BEGINCONFIG\n" + programInformation + self.totalEnv.returnConfigMaude() + "ENDCONFIG\n\n" + \
               "BEGINPOUS\n" + self.totalEnv.returnFBmaude(libFB) + "ENDPOUS\n"

    def updateFB(self):
        self.totalEnv.FBEnvDict = self.visitor.FBEnv

    def returnSwitch(self): return self.visitor.switch

"""
libFB = libDBmaker().makeBuiltINLibTypeFile("./libs")

typecheckerInstance = typeChecker(libFB)
typecheckerInstance.startTypeCheck("ma.txt")
stTranslatorInstance = stTranslator("ma.txt", typecheckerInstance.returnTotalEnv())
fileWriter = open("ma.maude", "w")
fileWriter.write(stTranslatorInstance.returnMaude())


typecheckerInstance = typeChecker(libFB)
typecheckerInstance.startTypeCheck("pms.txt")
stTranslatorInstance = stTranslator("pms.txt", typecheckerInstance.returnTotalEnv())
fileWriter = open("pms.maude", "w")
fileWriter.write(stTranslatorInstance.returnMaude())
"""