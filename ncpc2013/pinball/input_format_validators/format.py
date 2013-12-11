#!/usr/bin/env python

from os import linesep
from sys import stdin,exit
from re import search

def readints() :
    return (int(x) for x in stdin.readline().split())

n, = readints()
assert(0 <= n <= 100000)
for t in xrange(n) :
    x1,y1,x2,y2 = readints()
    assert (x1!=x2 and y1!= y2)
    for q in (x1,y1,x2,y2):
        assert (-1000000 <= q <= 1000000)
x0, = readints()
assert (-1000000 <= q <= 1000000)

exit(42)
