from copy import deepcopy
import re

def numTypes(): return ["NNUMINT", "PNUMINT", "NUMBIT", "NUMREAL"]
def usingedIntTypes(): return ['USINT', 'BYTE', 'UINT', 'WORD', 'UDINT', 'DWORD']
def intTypes(): return ["SINT", "USINT", 'BYTE', "INT", "UINT", 'WORD', "DINT", "UDINT", 'DWORD', "LINT", ]
def realTypes(): return ["REAL", "LREAL"]
def totalRealType() : return ["REAL", "LREAL", "NUMREAL"]
def boolType(): return ["BOOL"]
def everyDefaultTypes(): return intTypes() + realTypes() + boolType()

def defaultpOnDivZero():
    return "\n\nFUNCTIONBLOCK 'pOnDivZero \n" \
           "BEGINVAR\n" \
           "emptyVarDecl\n" \
           "ENDVAR\n" \
           "CODE\n" \
           "skip ;\n" \
           "ENDCODE\n" \
           "ENDFUNCTIONBLOCK\n\n"

class totalEnv:
    def __init__(self):
        self.programs = list()
        self.subprograms = list()
        self.udfbs = list()
        self.funcs = list()
        self.structures = list()
        self.globalVarEnv = dict()
        self.enumDict = dict()
        self.bitDict = dict()
        self.FBEnvDict = dict()
        self.cycleTime = ""

    def setFBs(self, pro, sub, udfb, struc):
        self.programs, self.subprograms, self.udfbs, self.structures = deepcopy(pro), deepcopy(sub), deepcopy(udfb), deepcopy(struc)
    def setGlobal(self, globalEnv): self.globalVarEnv = deepcopy(globalEnv)
    def setTypes(self, enums, bits):
        self.enumDict, self.bitDict = deepcopy(enums), deepcopy(bits)
    def setFBenv(self, fbenv):
        self.FBEnvDict = deepcopy(fbenv)
    def setCycleTime(self, cycleTime): self.cycleTime = cycleTime

    def returnCycleTimeMaude(self): return "CycleTime: # " + str(self.cycleTime)

    def returnConfigMaude(self):
        result = ""

        subproPart = "SUBPROGRAMS"
        for subpro in self.subprograms:
            subproPart += "\n'" + subpro + " ;;"

        subproPart += "\nSUBPROGRAMSEND"


        typePart = ""
        for type in self.enumDict.keys():
            typePart += self.enumDict[type].returnMaude()
        if typePart != "":  typePart = "\n\nTYPE\n" + typePart + "ENDTYPE\n\n"
        else: typePart = "\n\nTYPE\n" + "emptyTypeDecl\n" + "ENDTYPE\n\n"

        globalVarResult = ""
        for golbalVar in self.globalVarEnv.keys():
            self.globalVarEnv[golbalVar].setMaudeType(self.structures + list(self.bitDict.keys()) , self.udfbs, self.enumDict.keys())
            globalVarResult += self.globalVarEnv[golbalVar].returnMaude()
        if globalVarResult != "": globalVarResult = "\n\nBEGINVAR\n" + globalVarResult + "ENDVAR\n\n"
        else: globalVarResult = "\n\nBEGINVAR\n" + "emptyVarDecl\n" + "ENDVAR\n\n"

        result += subproPart + typePart + globalVarResult

        result += self.returnCycleTimeMaude() + "\n"

        return result

    def setMaudeVarType(self):
        for pro in self.programs + self.subprograms + self.udfbs + self.funcs + self.structures:
            for aVar in self.FBEnvDict[pro].varEnv.keys():
                self.FBEnvDict[pro].varEnv[aVar].setMaudeType(self.structures + list(self.bitDict.keys()) , self.udfbs, self.enumDict.keys())



    def returnFBmaude(self, libFB):
        self.setMaudeVarType()
        result = ""
        for pro in self.programs + self.subprograms + self.udfbs + self.funcs + self.structures:
            if pro in list(libFB.keys()): continue
            result += self.FBEnvDict[pro].returnMaude()

        for type in self.bitDict.keys():
            result += self.bitDict[type].returnMaude()


        return result


class FBEnv:
    def __init__(self):
        self.pouType = ""
        self.pouName = ""
        self.outputType = ""
        self.varEnv = dict()
        self.type = dict()
        self.inOrinoutParameter = list()
        self.outParamter = list()
        self.maudeCode = ""

    def setNameType(self, pouName, pouType, outputType):
        self.pouName, self.pouType, self.outputType = pouName, pouType, outputType

    def setParameter(self, localVars):
        self.inOrinoutParameter = list(filter(lambda x: x.useType in ["##IN", "##INOUT"], localVars))
        self.outParamter = list(filter(lambda x: x.useType =="##OUT",localVars))

    def setType(self, code, type): self.type[code] = type

    def setVarEnv(self, varList):
        for var in varList:
            self.varEnv[var.name] = deepcopy(var)

    def setGlobalEnv(self, globalEnv): self.varEnv = deepcopy(globalEnv)

    def mergeGlobalLocal(self, vars):
        for var in vars:
            self.varEnv[var.name] = deepcopy(var)
        self.setParameter(vars)
        self.setTypeOfVar()

    def setTypeOfVar(self):
        for varName in list(self.varEnv.keys()):
            self.type[varName] = self.varEnv[varName].type

    def returnMaude(self):
        if self.maudeCode == "": self.maudeCode = "skip ;"

        result = ""
        if self.pouType == "STRUCT":

            result += "STRUCT" + " '" + self.pouName + " \n" + \
                      self.returnMaudeFBvarDecl(strucSwitch=True) + "\n" + "ENDSTRUCT\n\n"

        elif self.pouType == "FUNCTION":
            result += self.pouType + " '" + self.pouName + " : " + self.outputType + " \n" + \
                      self.returnMaudeFBvarDecl() + "\nCODE\n" + self.maudeCode + "\nENDCODE\n" + "END" + self.pouType + "\n\n"

        elif self.pouType == "SUBPROGRAM":
            result += "FUNCTIONBLOCK" + " '" + self.pouName + " \n" + \
                      self.returnMaudeFBvarDecl() + "\nCODE\n" + self.maudeCode + "\nENDCODE\n" + "END" + "FUNCTIONBLOCK" + "\n\n"


        else:
            result += self.pouType.replace("_","") + " '" + self.pouName + " \n" + \
                      self.returnMaudeFBvarDecl() + "\nCODE\n" + self.maudeCode + "\nENDCODE\n" + "END" + self.pouType.replace("_","") + "\n\n"

        return result

    def returnMaudeFBvarDecl(self, strucSwitch=False):
        if strucSwitch:
            structVar = ""
            for var in self.varEnv.keys(): structVar += self.varEnv[var].returnMaude()
            if structVar == "": return "BEGINVAR\n" +  "emptyVarDecl\n" + "ENDVAR\n"
            else: return "BEGINVAR\n" +  structVar + "ENDVAR\n"


        returnResult = ""

        for var in self.varEnv.keys():
            if self.varEnv[var].useType == "##PRIV": returnResult += self.varEnv[var].returnMaude()
            elif self.varEnv[var].useType == "##OUT": returnResult += self.varEnv[var].returnMaude()
            elif self.varEnv[var].useType == "##IN": returnResult += self.varEnv[var].returnMaude()
            elif self.varEnv[var].useType == "##INOUT": returnResult += self.varEnv[var].returnMaude()
            else: continue

        if returnResult == "": return "BEGINVAR\n" +  "emptyVarDecl\n" + "ENDVAR\n"
        else: return "BEGINVAR\n" +  returnResult + "ENDVAR\n"


class Enumformat:
    def __init__(self, name, vars):
        self.name = name
        self.vars = vars

    def returnMaude(self):
        maueVars = list(map(lambda x: "'" + x, self.vars))
        return "'" + self.name + " ## ( " + " , ".join(maueVars) + " ) ; \n"

class BitFormat:
    def __init__(self, name, type, vars):
        self.name = name
        self.type = type
        self.vars = vars

    def returnMaude(self):
        processedList = list()
        for ith, aVar in enumerate(self.vars):
            processedList.append("'" + str(ith) + " : " + self.type + " : ##PRIV")
        return "STRUCT '" + self.name + "\nBEGINVAR\n" + " ; \n".join(processedList) + "\nENDVAR\nENDSTRUCT\n"

class VarFormat:
    def __init__(self, name, type, dim, init, useType=""):
        self.name = name
        self.type = type
        self.dim = dim
        self.useType = useType
        self.init = init

    def setUseType(self, useType): self.useType = useType

    def setInit(self):
        for ith, aIint in enumerate(self.init):
            if "t#" in aIint.lower():
                if "ms" in aIint.lower(): unit = "ms"
                elif "s" in aIint.lower(): unit = "ms"
                else:
                    print("Error : UNKNOWN TIMER UNIT --> " + aIint)
                    print("Choose S to run ")
                    unit = "s"


                numbers = re.findall("\d+", aIint)
                self.init[ith] = "T# " + numbers[0] + " " + unit

            else:
                if "TRUE" == aIint or "true" == aIint or "FALSE" == aIint or "false" == aIint:
                    self.init[ith] = aIint.upper()
                else:
                    self.init[ith] = "# " + aIint

    def setDefaultUseType(self):
        if self.useType == "": self.useType = "##PRIV"

    def setMaudeType(self, structres, functionblocks, enums):

        if self.type in structres:
            self.type = "structype [ '" + self.type + " ]"
        elif self.type in functionblocks: self.type = "fbtype [ '" + self.type + " ]"
        elif self.type in enums: self.type = "enumtype [ '" + self.type + " ]"
        else:
            if int(self.dim) > 0: self.type = "ARRAY [ # 0 .. # " + self.dim + " ] OF " + self.type
            return



    def returnMaude(self):
        self.setInit()
        self.setDefaultUseType()


        if len(self.init) == 0: return "'" + self.name + " : " + self.type + " : " + self.useType + " ; \n"
        else: return "'" + self.name + " : " + self.type + " := ( " + " , ".join(self.init) + " ) : " + self.useType + " ; \n"



