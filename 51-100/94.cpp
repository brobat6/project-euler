#include <bits/stdc++.h>
using namespace std;
#define int long long

const int B = 1000000000;

int check(int a, int c) {
    if(a + a + c > B) return 0;
    int x = sqrtl(a * a - (c * c / 4));
    if(x * x == a * a - (c * c / 4)) return a + a + c;
    return 0;
}

int32_t main() {
    int ans = 0;
    for(int a = 3; a <= B/3 + 5; a += 2) {
        ans += check(a, a + 1);
        ans += check(a, a - 1);
    }
    cout << ans << '\n';
}
