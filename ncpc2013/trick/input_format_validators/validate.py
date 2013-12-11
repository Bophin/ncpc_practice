#!/usr/bin/python
from sys import stdin
import re, sys

line = stdin.readline()
assert re.match("[123456789]\d{0,2}.\d{1,4}\n", line)

assert len(stdin.readline()) == 0
sys.exit(42)
