import glob
import os

oldname = []
newname = []

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/cb2-*-*[a-z].maude'):
    oldname += [name]
    newname += [name.replace('.maude', '-gcd3.maude')]

for i in range(len(oldname)):
    os.system('cp ' + oldname[i] + ' ' + newname[i])
