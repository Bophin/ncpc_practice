#!/usr/bin/python
from sys import stdin
import re
import sys

#constants
maxShots = 100000
maxAbsoluteCoordinate = 1000

#Line types are either integer or coordinate pair
integer = "(0|-?[1-9]\d*)"
oneint = re.compile(integer + "\n")
coordinatepair = re.compile(integer + " " + integer + "\n")

#Check number of lines
line = stdin.readline()
assert oneint.match(line)
c = int(line)
assert 1 <= c <= maxShots #~100.000 records to rule out O(N^2) solutions

#Check each line of coordinates
for test in range(c):
    line = stdin.readline()
    #Check that line matches expected format 
    assert coordinatepair.match(line)

    #Check that each specific token is within bounds
    tokens = line.split(' ')
    for token in tokens:
        i = int(token)
        assert abs(i) <= maxAbsoluteCoordinate

assert len(stdin.readline()) == 0
sys.exit(42)
