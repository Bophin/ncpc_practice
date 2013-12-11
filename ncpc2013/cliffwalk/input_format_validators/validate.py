#!/usr/bin/python
from sys import stdin
import re, sys

integerExp = '(0|-?[1-9]\\d*)'
floatExp = '(' + integerExp + '(.\\d+)?)'
integerExpRe = re.compile(integerExp)

# First line: "a m"
lineRe = re.compile(floatExp + ' ' + floatExp + '\n')
line = stdin.readline()
assert(lineRe.match(line))
(a, m) = (float(i) for i in line[:-1].split(' ',1))
assert(a > 0 and a < 15)
assert(m >= 0.1 and m <= 60)

# Second line: "w h x y"
lineRe = re.compile(' '.join([integerExp]*4) + '\n')
line = stdin.readline()
assert(lineRe.match(line))
(w, h, xs, ys) = (int(i) for i in line[:-1].split(' ',3))
assert(w >= 1 and w <= 200)
assert(h >= 1 and h <= 200)
assert(xs >= 0 and xs < w)
assert(ys >= 0 and ys < h)

# The map.
for y in range(h):
    line = stdin.readline()
    assert(line[-1] == '\n')
    tokens = line[:-1].split(' ')
    assert(len(tokens) == w)
    # Check each specific height value.
    for (x, token) in enumerate(tokens):
        assert(integerExpRe.match(token))
        z = int(token)
        assert(z >= 0 and z <= 20000)
        if (x == xs and y == ys):
            assert(z > a*1000)

assert len(stdin.readline()) == 0
sys.exit(42)
