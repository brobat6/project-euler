fif = []
for i in range(10):
    fif.append(i ** 5)

ans = 0

for i in range(2, 400000):
    x = 0
    s = str(i)
    for j in range(len(s)):
        x += fif[int(s[j])]
    if(x == i):
        ans += x
        print(x)

print(ans)
