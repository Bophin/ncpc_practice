#!/usr/bin/env python
# Generate a random map for the NCPC 2013 Cliff Walk problem
# Fredrik Svensson, Linkoping, 2013
import random
import sys

#Print usage if needed
def printUsage():
    print('usage: %s a m w h x y maxZ' % __file__)

# --------------------
# Things to execute

if len(sys.argv) != 8:
    printUsage()
    sys.exit(-1)

(a, m) = (float(s) for s in sys.argv[1:3])
(w, h, xs, ys, maxZ) = (int(s) for s in sys.argv[3:])
assert(a*1000 < maxZ)

print('%f %f' % (a, m))
print('%d %d %d %d' % (w, h, xs, ys))

for y in range(0, h):
    zValues = [random.randint(0, maxZ) for x in range(0, w)]
    if (y == ys):
        zValues[xs] = maxZ
    print(' '.join([str(z) for z in zValues]))
