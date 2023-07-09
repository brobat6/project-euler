N = 1000000

def is_palindromic(s):
    for i in range(len(s)):
        if(s[i] != s[len(s) - i - 1]):
            return False
    return True

ans = 0

for d in range(N):
    b = str(bin(d))[2::]
    if(is_palindromic(str(d)) and is_palindromic(b)):
        ans += d

print(ans)
