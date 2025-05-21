import glob
import os
import fileinput

oldname = []
newname = []

for name in glob.glob('/home/jlee/plc-release/apps/icalpexp/*-n-gcd3.maude'):
    with open(name, 'r') as file:
        data = file.readlines()
        data[-18] = "     = counter(s N, metaSrewrite(upModule('POR, false), upTerm(appExt), ('noPor)[[empty]], breadthFirst, s N)) .\n"
        data[-5] = "red counter(0, metaSrewrite(upModule('POR, false), upTerm(appExt), ('noPor)[[empty]], breadthFirst, 0)) .\n"
    with open(name, 'w') as file:
        file.writelines(data)
