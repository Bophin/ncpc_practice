#!/usr/bin/env python
import random
import argparse

# parse arguments
parser = argparse.ArgumentParser(description='Generate test data for problem with ID: erase')
parser.add_argument('--min_sweeps', metavar='n', default=1,    type=int, help='Minimum number of bit sweeps')
parser.add_argument('--max_sweeps', metavar='n', default=20,   type=int, help='Maximum number of bit sweeps')
parser.add_argument('--min_bits',   metavar='l', default=1,    type=int, help='Minimum number of file bits')
parser.add_argument('--max_bits',   metavar='l', default=1000, type=int, help='Maximum number of file bits')
parser.add_argument('--failed',     nargs='?', metavar='k', default=None, type=int, const=0, help='Number of incorrectly erased bits. When no argument given, k is chosen randomly.')
args = parser.parse_args()
# number of sweeps and number of file bits
n = random.randrange(args.min_sweeps, args.max_sweeps+1)
l = random.randrange(args.min_bits,   args.max_bits  +1)
# file bits before removal
a = bin(random.getrandbits(l))[2:]
# file bits after successful removal
if n % 2: b = a.replace('0', '2').replace('1', '0').replace('2', '1')
else:     b = a
# produce failed deletion case by flipping a random number of bits
if args.failed != None:
  b = list(b)
  if args.failed < 1:      args.failed = random.randrange(1, len(b)+1)
  if args.failed > len(b): args.failed = len(b)
  r = random.sample(xrange(len(b)), args.failed)
  for i in r:
    if b[i] == '0': b[i] = '1'
    else:           b[i] = '0'
  b = ''.join(b)
# print test input
print n
print a
print b
