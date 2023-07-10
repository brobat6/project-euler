MOD = 1_000_000_000_0

def binpow(a, b):
    if(b == 0):
        return 1
    x = binpow(a, b // 2)
    if(b % 2 == 0):
        return x * x % MOD
    return x * x * a % MOD

print((28433 * binpow(2, 7830457) + 1) % MOD)
