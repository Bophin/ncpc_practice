#!/usr/bin/python
from sys import stdin
import re
import sys

integer = "(0|[1-9]\d*)"
floating = integer + "(\.\d+)?"
onefloat = re.compile(floating + "\n")
sixfloat = re.compile("(" + floating + " ){5}" + floating + "\n")

line = stdin.readline()
assert sixfloat.match(line)
a = [float(x) for x in line.split()]
for i in range(5):
    assert a[i] < a[i + 1]
assert 0 < a[0] and a[5] <= 100

line = stdin.readline()
assert onefloat.match(line)
s = float(line)
assert 0 < s <= 100

assert len(stdin.readline()) == 0
sys.exit(42)
