arr = list(map(int, input().split(',')))

# print(ord('a'))
# print(chr(97))

for i in range(26):
    for j in range(26):
        for k in range(26):
            A = list()
            for x in arr:
                A.append(x)
            B = []
            count = 0
            for x in range(len(A)):
                if(x % 3 == 0):
                    A[x] ^= 97 + i
                if(x % 3 == 1):
                    A[x] ^= 97 + j
                if(x % 3 == 2):
                    A[x] ^= 97 + k
                if ((A[x] >= 65 and A[x] < 65 + 26) or (A[x] >= 97 and A[x] < 97 + 26)):
                    count += 1
                B.append(A[x])
            if(count > 1050):
                print(i, j, k)
                for t in B:
                    print(chr(t), end = '')
                print()
                print()

# 4, 23, 15 is the answer

sum = 0
for x in range(len(arr)):
    if(x % 3 == 0):
        sum += arr[x] ^ (97 + 4)
    if(x % 3 == 1):
        sum += arr[x] ^ (97 + 23)
    if(x % 3 == 2):
        sum += arr[x] ^ (97 + 15)

print(sum)
