# 4d * 1d, 3d * 2d

def add(p, x):
    for i in range(len(str(x))):
        p[int(str(x)[i])] += 1
    return p

def solve(x, y):
    z = x * y
    p = dict()
    for i in range(10):
        p[i] = 0
    p = add(p, x)
    p = add(p, y)
    p = add(p, z)
    if(p[0] > 0):
        return False
    for i in range(1, 10):
        if(p[i] != 1):
            return False
    return True

ans = list()

for i in range(100, 1000):
    for j in range(10, 100):
        if(solve(i, j)):
            ans.append(i * j)

for i in range(1000, 10000):
    for j in range(1, 10):
        if(solve(i, j)):
            ans.append(i * j)

print(sum(set(ans)))
