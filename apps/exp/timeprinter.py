import glob
import os
import fileinput

oldname = []
newname = []

prefix = input("log-abs-?: ")

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/log-abs-' + prefix + '*.log'):
    with open(name, 'r') as file:
        data = file.readlines()
        print(name + "   " + data[-4])
