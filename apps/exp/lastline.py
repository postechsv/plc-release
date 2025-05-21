import glob
import os
import fileinput

oldname = []
newname = []

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/*-*.maude'):
    with open(name, 'r') as file:
        data = file.readlines()
        print(name)
        print(data[-5])
