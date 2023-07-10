from math import log2

max_value = 0.0
ans_line = 0

for i in range(1000):
    a, b = map(float, input().split(','))
    curr = b * log2(a)
    if(curr > max_value):
        max_value = curr
        ans_line = i + 1

print(max_value, ans_line)
