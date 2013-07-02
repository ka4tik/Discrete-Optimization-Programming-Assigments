#!/usr/bin/python
# -*- coding: utf-8 -*-
from random import randrange 
import os 
from subprocess import Popen,PIPE

def solveIt(n):
    
    #process=Popen(['./8queens',str(n)],stdout=PIPE)
    #(stdout,stderr)=process.communicate()

    inputDataFile = open('sol', 'r')
    inputData = ''.join(inputDataFile.readlines())
    inputDataFile.close()
    
    #return stdout.strip()
    return inputData.strip()
import sys

if __name__ == "__main__":
    if len(sys.argv) > 1:
        try:
            n = int(sys.argv[1].strip())
        except:
            print sys.argv[1].strip(), 'is not an integer'
        print 'Solving Size:', n
        print(solveIt(n))

    else:
        print('This test requires an instance size.  Please select the size of problem to solve. (i.e. python queensSolver.py 8)')

