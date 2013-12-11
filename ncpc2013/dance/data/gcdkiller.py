#!/usr/bin/env python3
import random

# n, k = 432, 12
# sz = 18
# n, k = 2250, 75
# sz = 5
n, k = 2225, 75 # Impossible
sz = 5

a = [i for i in range(n)]
random.shuffle(a)

b = []
while len(b) < n:
    add = range(len(b), len(b) + sz)
    b.extend(add[(i + 1) % sz] for i in range(sz))

c = [0] * n
for i in range(n):
    c[a[i]] = a[b[i]]

print(n, k)
print(" ".join(str(x + 1) for x in c))
