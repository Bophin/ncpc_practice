#!/usr/bin/python
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
floating = "0.\d\d"
floatint = re.compile(floating + " " + integer + "\n")
twoint = re.compile("(" + integer + " ){1}" + integer + "\n")
manyint = re.compile("(" + integer + " )*" + integer + "\n")

line = stdin.readline()
assert floatint.match(line)
q = line.split()
t, n = float(q[0]), int(q[1])
assert 0.5 < t < 1 and 1 <= n <= 1000

line = stdin.readline()
assert manyint.match(line)
a = list(map(int, line.split()))
assert len(a) == n
for x in a:
    assert 1 <= x <= 10 ** 6

assert len(stdin.readline()) == 0
sys.exit(42)
