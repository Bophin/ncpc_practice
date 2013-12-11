#!/usr/bin/env python3
import random
import math
import bisect
import sys
from sys import stdin


def pow(a, k):
    n = len(a)
    seen = [False] * n
    res = [-1] * n
    for i in range(n):
        if not seen[i]:
            u = i
            cyc = []
            while not seen[u]:
                seen[u] = True
                cyc.append(u)
                u = a[u]

            for i in range(len(cyc)):
                res[cyc[i]] = cyc[(i + k) % len(cyc)]
    return res


def divisors(k):
    for i in range(1, math.ceil(math.sqrt(k))):
        if k % i == 0:
            yield i
            if i * i < k:
                yield k // i


def factor(k):
    for i in range(2, math.ceil(math.sqrt(k))):
        if k % i == 0:
            cnt = 0
            while k % i == 0:
                cnt += 1
                k //= i
            yield (i, cnt)
    if k > 1:
        yield (k, 1)


s = stdin.readline().strip().split()
pos = 3
if s[0] == "exactly":
    n, k = int(s[1]), int(s[2])
else:
    n = random.randint(int(s[1]), int(s[2]))
    k = random.randint(int(s[3]), int(s[4]))
    pos += 2

print(n, k)

a = [i for i in range(n)]
random.shuffle(a)
typ = s[pos]
if typ == "clever":
    q = [x for x in divisors(k)]
    q.sort()

    b = []
    while True:
        ok = True
        while len(b) < n:
            ind = random.randint(0, bisect.bisect(q, n - len(b)) - 1)
            mul = q[ind]
            sz = random.randint(1, (n - len(b)) // mul) * mul
            add = range(len(b), len(b) + sz)
            if sz == 1 and random.randint(0, 3) > 0:
                ok = False
            b.extend(add[(i + 1) % sz] for i in range(sz))

        if ok:
            break
        else:
            b = []

    c = [0] * n
    for i in range(n):
        c[a[i]] = a[b[i]]
    a = c

res = pow(a, k)
print(" ".join(str(x + 1) for x in res))
