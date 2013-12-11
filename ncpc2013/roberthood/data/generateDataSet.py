#!/usr/bin/env python
# Generate a scatter of points for the NCPC 2013 Archery problem
# Daniel Espling, Umea University, 2011

import random
import sys

#Print usage if needed
def printUsage():
    print "usage: %s <numberOfPoints, <= 100000>" % __file__
    print "example: %s 10000\n" % __file__

# --------------------
# Things to execute

if len(sys.argv) != 2:
    printUsage()
    sys.exit(-1)

nrPoints = int(sys.argv[1])

if nrPoints > 100000:
    print "nrPoints higher than max problem input size (%d)" % nrPoints
    sys.exit(-2)

minCoordinate = -1000;
maxCoordinate = 1000;

#Print coordinates
print nrPoints
for i in range(0, nrPoints):
    x = random.randint(minCoordinate, maxCoordinate)
    y = random.randint(minCoordinate, maxCoordinate)
    print "%d %d" % (x, y)
