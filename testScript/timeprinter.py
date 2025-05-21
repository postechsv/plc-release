import glob
import os
import fileinput

oldname = []
newname = []

for name in sorted(glob.glob('/home/jlee/plc-release/testScript/*.log')):
    with open(name, 'r') as file:
        data = file.readlines()
        if(len(data) > 0):
            print(name + "   " + data[-1])
