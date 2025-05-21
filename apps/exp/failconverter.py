import glob
import os
import fileinput

oldname = []
newname = []

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/*-*.maude'):
    with open(name, 'r') as file:
        data = file.readlines()
        data[-5] = data[-5].replace(' .', ' ; fail .')
    with open(name, 'w') as file:
        file.writelines(data)
