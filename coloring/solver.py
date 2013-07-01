#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
from subprocess import PIPE,Popen

def solveIt(inputData):
    # Modify this code to run your optimization algorithm
    
    tmpFileName = 'tmp.data'
    tmpFile = open(tmpFileName, 'w')
    tmpFile.write(inputData)
    tmpFile.close()


    process = Popen(['./coloring', tmpFileName],stdout=PIPE)
    (stdout, stderr) = process.communicate()

    # removes the temporay file

    os.remove(tmpFileName)

    return stdout.strip()


import sys

if __name__ == '__main__':
    if len(sys.argv) > 1:
        fileLocation = sys.argv[1].strip()
        inputDataFile = open(fileLocation, 'r')
        inputData = ''.join(inputDataFile.readlines())
        inputDataFile.close()
        print solveIt(inputData)
    else:
        print 'This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/gc_4_1)'

