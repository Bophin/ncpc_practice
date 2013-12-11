#!/usr/bin/python
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
oneint = re.compile(integer + "\n")
manyint = re.compile("({0} )*{0}\n".format(integer))

line = stdin.readline()
assert oneint.match(line)
n = int(line)
assert 1 <= n <= 10 ** 5

line = stdin.readline()
assert manyint.match(line)
a = list(map(int, line.split()))
assert len(a) == n
for x in a:
    assert 1 <= x <= 10 ** 6

assert len(stdin.readline()) == 0
sys.exit(42)
