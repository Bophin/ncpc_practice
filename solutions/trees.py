#!/usr/bin/python

import string
from sys import stdin


N = stdin.readline()
list = stdin.readline()
nums = sorted(map(int, string.split(list)), reverse=True)
days = 0
for i in range(len(nums)):
	days = max(days,nums[i]+(i+1))
print days+1
	
