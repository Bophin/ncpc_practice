#!/usr/bin/python

import sys

line1 = sys.stdin.readline()
line2 = sys.stdin.readline()

minlen = min(len(line1),len(line2))

diff = len(line1) - len(line2)

first = minlen
last = max(0,len(line2)-len(line1))

for i in range(minlen):
	if line1[i] != line2[i]:
		first = i
		break

for i in range(len(line1)):
	j = len(line1)-1-i
	if (line1[j] != line2[j-diff]):
		last = j
		break

print last - first
