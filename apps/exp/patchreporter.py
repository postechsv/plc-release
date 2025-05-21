import glob
import os
import fileinput

oldname = []
newname = []

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/*.maude'):
    with open(name, 'r') as file:
        data = file.readlines()
        data[-31] = '\n  strat ample @ KConfig .\n  sd ample := ((pjRed | tick) ? idle : (rest | noMem))* .\n  strat internal @ KConfig .\n sd internal := (noMem ? idle : (rest | tick | pjRed))* .\n ---('
    with open(name, 'w') as file:
        file.writelines(data)
