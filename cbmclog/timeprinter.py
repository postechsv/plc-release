import glob
import os
import fileinput

oldname = []
newname = []

for name in sorted(glob.glob('/home/jlee/plc-release/cbmclog/*.log')):
    with open(name, 'r') as file:
        data = file.readlines()
        print(name + "   " + data[-2])
