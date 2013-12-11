#!/usr/bin/python
from sys import stdin
import re, sys

for i in range(2):
    line = stdin.readline()
    assert 1 <= len(line)-1 <= 10**5
    assert re.match("[ACGT]+\n", line)

assert len(stdin.readline()) == 0
sys.exit(42)
