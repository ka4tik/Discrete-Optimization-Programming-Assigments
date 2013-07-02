#!/usr/bin/python
# -*- coding: utf-8 -*-
from random import randrange 

def solveIt(n):
    # Modify this code to run your puzzle solving algorithm
    
    sol=range(n)

    while checkit(sol)==False:
        indexes=[];
        m=0;
        for i in xrange(n):#find the position with maximum voilations 
            d=checkone(sol,i,n)
            if d>m:
               m=d;
        for i in xrange(n):#find the position with maximum voilations 
            d=checkone(sol,i,n)
            if d==m:
                indexes.append(i)
        index=indexes[randrange(len(indexes))];
        m2=checkone(sol,index,n);
        for i in range(n): #find the position with minimum voilations  
            sol[index]=i
            d=checkone(sol,index,n)
            if d<m2:
                m2=d
        indexes=[]
        for i in range(n):
            sol[index]=i;
            d=checkone(sol,index,n)
            if d==m2:
                indexes.append(i)
        index2=indexes[randrange(len(indexes))];
        sol[index]=index2;
            
    # prepare the solution in the specified output format
    # if no solution is found, put 0s
    outputData = str(n) + '\n'
    if sol == None:
        print 'no solution found.'
        outputData += ' '.join(map(str, [0]*n))+'\n'
    else: 
        outputData += ' '.join(map(str, sol))+'\n'
        
    return outputData



def checkone(sol,index,n):
    ret=0;
    for i in range(0,n):
            if i==index:
               continue
            elif sol[i] == sol[index] or \
               sol[i] == sol[index] + (index-i) or \
               sol[i] == sol[index] - (index-i):
               ret=ret+1;
    return ret
# checks if an assignment is feasible
def checkit(sol):
    n = len(sol)
    for i in range(0,n):
        for j in range(i+1,n):
            if sol[i] == sol[j] or \
               sol[i] == sol[j] + (j-i) or \
               sol[i] == sol[j] - (j-i):
                return False
    return True


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

