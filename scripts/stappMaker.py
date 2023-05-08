import os.path

from dclProcessor import dclStappMaker

class StappFileMaker:
    def __init__(self, scriptPath, projectPath):
        self.scriptPath = scriptPath
        self.projectPath = projectPath
        self.dclStMaker = dclStappMaker()

    def returnApplik5p(self): return self.projectPath + "/appli.k5p"
    def makeConfig(self): return self.dclStMaker.makeStGlobalConfig(self.returnApplik5p())
    def makePOUS(self):
        POUS = ""
        STRUCTURES = ""

        for program in self.dclStMaker.returnPrograms():
            dclfilePath = self.projectPath + "/" + program + ".dcl"
            srcFilePath = self.projectPath + "/" + program + ".src"
            POUS += "PROGRAM " + self.makePOU(program, dclfilePath, srcFilePath) + "END_PROGRAM\n\n"

        for subprogram in self.dclStMaker.returnSubprograms():
            dclfilePath = self.projectPath + "/" + subprogram + ".dcl"
            srcFilePath = self.projectPath + "/" + subprogram + ".src"
            POUS +=  "SUBPROGRAM " + self.makePOU(subprogram, dclfilePath, srcFilePath) + "END_SUBPROGRAM\n\n"

        for udfb in self.dclStMaker.returnUdfbs():
            dclfilePath = self.projectPath + "/" + udfb + ".dcl"
            srcFilePath = self.projectPath + "/" + udfb + ".src"
            POUS +=  "FUNCTION_BLOCK " + self.makePOU(udfb, dclfilePath, srcFilePath) + "END_FUNCTION_BLOCK\n\n"

        for structure in self.dclStMaker.returnStructures():
            dclfilePath = self.projectPath + "/" + structure + ".dcl"
            notProcessed = self.makePOU(structure, dclfilePath, "NONE", True)
            STRUCTURES += structure + " : \n" + notProcessed.replace("VAR", "STRUCT").replace("END_VAR", "END_STRUCT")

        return POUS, STRUCTURES


    def makePOU(self, unitName, dclPath, srcPath, structureSwitch=False):
        if not (os.path.isfile(dclPath)): dclContent = ""
        else: dclContent = dclStappMaker().makeStLocalVarDecl(dclPath)

        if structureSwitch:
            return dclContent

        else:
            if not (os.path.isfile(srcPath)): srcContent = ""
            else: srcContent = open(srcPath, 'r').read()
            return unitName + "\n" + dclContent + srcContent



    def makeStapp(self):
        programConfig, typeConfig, globalVarConfig = self.makeConfig()
        POUS, STRUCTURES = self.makePOUS()
        typeConfig = "TYPE\n" +  typeConfig + STRUCTURES +"END_TYPE\n"
        #print(globalVarConfig)
        return programConfig + "\n" + typeConfig + "\n" + globalVarConfig + "\n" + POUS



