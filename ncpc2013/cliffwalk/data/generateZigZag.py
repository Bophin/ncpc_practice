#!/usr/bin/env python
# Generate a random map for the NCPC 2013 Cliff Walk problem
# Fredrik Svensson, Linkoping, 2013
import random
import sys

#Print usage if needed
def printUsage():
    print('usage: %s a m w h maxZ variant' % __file__)

# --------------------
# Things to execute

if len(sys.argv) != 7:
    printUsage()
    sys.exit(-1)

(a, m) = (float(s) for s in sys.argv[1:3])
(w, h, maxZ, variant) = (int(s) for s in sys.argv[3:])
assert(a*1000 < maxZ)
minZ = a*1000 + 1

zMap = [[0]*w for i in range(0, h)]

if (variant == 1):
    xs = w-1
    ys = 0
    for y in range(0, h, 2):
        for x in range(0, w):
            zMap[y][x] = random.randint(minZ, maxZ)
        if (y+1 < h):
            zMap[y+1][0 if (y%4 == 0) else w-1] = random.randint(minZ, maxZ)
elif (variant == 2):
    xs = 0
    ys = h-1
    for x in range(0, w, 2):
        for y in range(0, h):
            zMap[y][x] = random.randint(minZ, maxZ)
        if (x+1 < w):
            zMap[0 if (x%4 == 0) else h-1][x+1] = random.randint(minZ, maxZ)
elif (variant == 3):
    xs = int(w/2)
    ys = int(h/2)
    for i in range(0, int(min(w,h)/2), 2):
        for x in range(i, w-i):
            zMap[i][x] = random.randint(minZ, maxZ)
            zMap[h-i-1][x] = random.randint(minZ, maxZ)
        for y in range(i, h-i):
            zMap[y][i] = random.randint(minZ, maxZ)
        for y in range(i, h-i-2):
            zMap[y][w-i-1] = random.randint(minZ, maxZ)
        zMap[h-i-3][w-i-2] = random.randint(minZ, maxZ)
    zMap[ys][xs] = random.randint(minZ, maxZ)
else:
    raise Exception('Invalid variant %s.' % variant)

print('%f %f' % (a, m))
print('%d %d %d %d' % (w, h, xs, ys))
for y in range(0, h):
    print(' '.join([str(z) for z in zMap[y]]))
