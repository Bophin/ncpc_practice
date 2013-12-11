#!/usr/bin/python

import os
import string
import subprocess
import sys

DEVNULL = open(os.devnull, 'wb')
OUTPUT = "temp_executable"

def compile_go(src):
	print "COMPILING GO\n"
	subprocess.check_output(["go", "build", "-o", OUTPUT, src])
	return OUTPUT

def ends_with(s, end):
	pos = len(s)-len(end)
	if pos > 0:
		return s[pos:] == end
	else:
		return False

def same_start(s1, s2):
	s1 = string.strip(s1,'.in')
	s2 = string.strip(s2,'.ans')
	return s1 == s2


def validate(arg, dirname, fnames):
	print "EXECUTING"

	indata = filter(lambda x: ends_with(x, '.in'), fnames)
	outdata = filter(lambda x: ends_with(x, '.ans'), fnames)
	
	if indata and outdata:
		together = [(x,y) for x in indata for y in outdata if same_start(x,y)]
		for pair in together:
			#exec arg with indata as input and store output
			output = subprocess.check_output(arg, stdin=open(dirname + '/' + pair[0]))
			#compare outdata from exec with expected data
			with open(dirname + '/' + pair[1]) as outfile:
				expected = outfile.read()
				if output == expected:
					print pair[0], "OK"
				else:
					print "Wrong answer for", pair[0]
					print "Expected:", expected
					print "Output:", output
					#sys.exit(1)

if __name__ == '__main__':
	if (len(sys.argv) == 3):
		source = sys.argv[2]
		if ends_with(source, ".go"):
			executable = compile_go(source)
		else:
			executable = source
		os.path.walk(sys.argv[1], validate, os.getcwd() + '/' + executable)
		if os.path.exists(os.getcwd() + '/' + OUTPUT):
			os.remove(os.getcwd() + '/' + OUTPUT)
	else:
		print "Usage:",sys.argv[0], "[inputdir] [executable]"
