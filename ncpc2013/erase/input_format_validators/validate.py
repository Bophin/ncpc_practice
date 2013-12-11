#! /usr/bin/env python

from sys import stdin
import re
import sys

posint = re.compile('([1-9]\d*)\n')
bitstr = re.compile('[01]+\n')

# number of bit sweeps
n = stdin.readline()
assert posint.match(n)
n = int(n)
assert 1 <= n <= 20

# file bits before deletion
a = stdin.readline()
assert bitstr.match(a)
assert 1 <= len(a) <= 1000

# file bits after deletion
b = stdin.readline()
assert bitstr.match(b)
assert len(b) == len(a)

sys.exit(42)
