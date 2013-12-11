#!/usr/bin/python
from sys import stdin
import re
import sys

string = re.compile("([* ]{3} )+[* ]{3}\n")

for q in range(5):
    line = stdin.readline()
    assert string.match(line)
    assert len(line) % 4 == 0
    ln = len(line) // 4
    assert 2 <= ln <= 8

assert len(stdin.readline()) == 0
sys.exit(42)
