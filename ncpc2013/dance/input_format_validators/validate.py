#!/usr/bin/python
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
twoint = re.compile(integer + " " + integer + "\n")
manyint = re.compile("(" + integer + " )*" + integer + "\n")

line = stdin.readline()
assert twoint.match(line)
a = line.split()
n, k = int(a[0]), int(a[1])
assert 2 <= n <= 10 ** 4 and 1 <= k <= 10 ** 9

line = stdin.readline()
assert manyint.match(line)
a = list(map(int, line.split()))
a.sort()
assert a == range(1, n + 1)

assert len(stdin.readline()) == 0
sys.exit(42)
