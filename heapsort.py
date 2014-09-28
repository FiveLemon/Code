#!/usr/bin/envpython
# -*- coding: utf-8 -*-
def PARNET(i):
    return int((i - 1) / 2)

def LEFT(i):
    return 2 * i + 1

def RIGHT(i):
    return 2 * i + 2

def MAX_HEAPIFY(A,i,length):
    l = LEFT(i)
    r = RIGHT(i)
    #largest = 0
    if l < length and A[l] > A[i]:
        largest = l
    else:
        largest = i

    if r < length and A[r] > A[largest]:
        largest = r

    if largest != i:
        temp = A[i]
        A[i] = A[largest]
        A[largest] = temp
        MAX_HEAPIFY(A,largest, length)


def BUILD_MAX_HEAP(A):
    length = len(A)
    for i in range(len(A)/2 - 1,-1,-1):
        MAX_HEAPIFY(A,i,length)


def HEAPSORT(A):
    BUILD_MAX_HEAP(A)

    for i in range(len(A) - 1,0,-1):
        temp = A[0]
        A[0] = A[i]
        A[i] = temp
        MAX_HEAPIFY(A, 0, i)



A = [4,1,3,2,16,9,10,14,8,7,99]
#print A
#BUILD_MAX_HEAP(A)
#print A
HEAPSORT(A)
#MAX_HEAPIFY(A,1)
print A
