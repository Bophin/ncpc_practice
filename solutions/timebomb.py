#!/usr/bin/python

from sys import stdin
import sys
import string

zero = ("***"
        "* *"
	    "* *"
	    "* *"
	    "***")
one = ("  *"
       "  *"
	   "  *"
	   "  *"
	   "  *")
two = ("***"
       "  *"
	   "***"
	   "*  "
	   "***")
three = ("***"
         "  *"
	     "***"
	     "  *"
	     "***")
four = ("* *"
        "* *"
	    "***"
	    "  *"
	    "  *")
five = ("***"
        "*  "
	    "***"
	    "  *"
	    "***")
six =  ("***"
        "*  "
	    "***"
	    "* *"
	    "***")
seven = ("***"
         "  *"
	     "  *"
	     "  *"
	     "  *")
eight = ("***"
         "* *"
	     "***"
	     "* *"
	     "***")
nine =  ("***"
         "* *"
	     "***"
	     "  *"
	     "***")

def get_number(num):
	if num == zero: return 0
	if num == one: return 1
	if num == two: return 2
	if num == three: return 3
	if num == four: return 4
	if num == five: return 5
	if num == six: return 6
	if num == seven: return 7
	if num == eight: return 8
	if num == nine: return 9
	else: return -1

line1 = stdin.readline()
line2 = stdin.readline()
line3 = stdin.readline()
line4 = stdin.readline()
line5 = stdin.readline()

nums = (len(line1)+1) / 4

code = 0

for i in range(nums):
	l1 = line1[i*4:i*4+3]
	l2 = line2[i*4:i*4+3]
	l3 = line3[i*4:i*4+3]
	l4 = line4[i*4:i*4+3]
	l5 = line5[i*4:i*4+3]
	n = get_number(l1+l2+l3+l4+l5)
	if n == -1:
		print "BOOM!!"
		sys.exit(0)
	code *= 10
	code += n

if code % 6:
	print "BOOM!!"
else:
	print "BEER!!"

