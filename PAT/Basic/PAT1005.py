#!/usr/bin/python  
# -*- coding: utf-8 -*- 
'''
Created on 2014年9月16日

@author: qcq
acquired help from: cxp

The description of this file:
        #English#
            The reason to write this file, what contains in this file. What is the most import function in this file or 
        what specific algorithm implemented in this file's code.
        
        N: The important common parameters should　list here.
        
The change records:
            Time     Changed By    Reason
       2014年9月16日        qcq
        ...              ...        ...
'''
def CutNumber(temp):
    global data
    data.append(temp)
    while temp > 1:
        if 0 == temp % 2:
            temp = temp / 2
            data.append(temp)
        else:
            temp = (3 * temp + 1) / 2
            data.append(temp) 

if __name__ == '__main__':
    data = []
    temp1 = []
    a = int(raw_input().strip())
    b = raw_input().strip().split(' ')
    for index in range(a):
        data = []
        for index_2 in range(a):
            if index_2 != index:
                CutNumber(int(b[index_2]))
            if data.count(int(b[index])):
                break;
        if  0 == data.count(int(b[index])):
            temp1.append(int(b[index]))
    temp1.sort()
    temp1.reverse()
    string = ''
    for i in temp1:
        string+=str(i) + ' '
    string = string[0:len(string) - 1]
    print string