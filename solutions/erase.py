#!/usr/bin/python

import string
import os
import fileinput
import sys

same = int(sys.stdin.readline()) % 2 == 0

first = sys.stdin.readline()
second = sys.stdin.readline()

if same:
	if first == second:
		print "Deletion succeeded"
	else:
		print "Deletion failed"
else:
	if second.replace('0','2').replace('1','0').replace('2','1') == first:
		print "Deletion succeeded"
	else:
		print "Deletion failed"

