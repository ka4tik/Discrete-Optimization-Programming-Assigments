#!/usr/bin/python
# -*- coding: utf-8 -*-

def knapSack(W,wt,val,n):
    dp=[ [0 for i in range(W+1)] for j in range(n+1)]
    pick=[ [0 for i in range(W+1)] for j in range(n+1)]
    
    for i in xrange(n+1):
       for w in xrange(W+1):

           if w==0 or i==0:
               dp[i][w]=0
           elif wt[i-1]<=w:
               dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w])
               if val[i-1]+dp[i-1][w-wt[i-1]]>dp[i-1][w]:
                   pick[i][w]=1;
               else:
                   pick[i][w]=-1;
           else: 
               pick[i][w]=-1;
               dp[i][w]=dp[i-1][w];

    #print "maximum values is " + str(dp[n][W]);

    current=n;
    ret=[];
    while current>0:
         #print current,W;
         if pick[current][W]==1:
             ret.append(1);
             W=W-wt[current-1];
             current=current-1;
         else:
             ret.append(0);
             current=current-1
    ret=ret[::-1];
    return ret;

def solveIt(inputData):
    # Modify this code to run your optimization algorithm

    # parse the input
    lines = inputData.split('\n')

    firstLine = lines[0].split()
    items = int(firstLine[0])
    capacity = int(firstLine[1])

    values = []
    weights = []

    for i in range(1, items+1):
        line = lines[i]
        parts = line.split()

        values.append(int(parts[0]))
        weights.append(int(parts[1]))

    items = len(values)

    # a trivial greedy algorithm for filling the knapsack
    # it takes items in-order until the knapsack is full
    value = 0
    weight = 0
    taken = []
    taken=knapSack(capacity,weights,values,items);
    
    for i in xrange(items):
        if taken[i]==1:
            value=value+values[i];

    #for i in range(0, items):
        #if weight + weights[i] <= capacity:
            #taken.append(1)
            #value += values[i]
            #weight += weights[i]
        #else:
            #taken.append(0)

    

    # prepare the solution in the specified output format
    outputData = str(value) + ' ' + str(1) + '\n'
    outputData += ' '.join(map(str, taken))
    return outputData


import sys

if __name__ == '__main__':
    if len(sys.argv) > 1:
        fileLocation = sys.argv[1].strip()
        inputDataFile = open(fileLocation, 'r')
        inputData = ''.join(inputDataFile.readlines())
        inputDataFile.close()
        print solveIt(inputData)
    else:
        print 'This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)'

