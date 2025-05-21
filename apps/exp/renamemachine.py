import glob
import os

oldname = []
newname = []

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/log-gcd-cb2-*'):
    oldname += [name]
    newname += [name.replace('gcd', 'con')]

for i in range(len(oldname)):
    os.system('mv ' + oldname[i] + ' ' + newname[i])
