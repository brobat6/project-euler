#include <bits/stdc++.h>
using namespace std;

int calculate(int a, int b, int c, int d) {
    set <double> dp[16];
    dp[1].insert(a);
    dp[2].insert(b);
    dp[4].insert(c);
    dp[8].insert(d);
    auto COMBINE = [&](int x, int y) {
        for(auto a : dp[x]) {
            for(auto b : dp[y]) {
                dp[x|y].insert(a + b);
                dp[x|y].insert(a - b);
                dp[x|y].insert(b - a);
                dp[x|y].insert(a * b);
                if(b != 0) dp[x|y].insert(a*1.0 / b);
                if(a != 0) dp[x|y].insert(b*1.0 / a);
            }
        }
    };
    for(int i = 1; i < 16; i++) {
        for(int j = i - 1; j > 0; j--) {
            if((i | j) == i) {
                // cout << i << ' ' << j << '\n';
                COMBINE(j, i - j);
            }
        }
        // cout << i << ":";
        // for(auto j : dp[i]) cout << j << ",";
        // cout << '\n';
    }
    // int cnt = 0;
    set <int> s;
    for(auto i : dp[15]) if(i > 0 && abs(i - round(i)) <= 1E-6) {
        // cnt++;
        // cout << i << ' ';
        s.insert(round(i));
    }
    // cout << '\n' << cnt << '\n';
    // for(auto i : s) cout << i << ' '; cout << '\n';
    // cout << s.size() << '\n';
    int mx = 1;
    for(auto i : s) {
        if(i == mx) mx++;
        else break;
    }
    if(mx > 28) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << ':' << mx << '\n';
    }
    return 0;
}

int main() {
    int MX = 10;
    // calculate(1, 2, 3, 4);
    for(int i = 1; i < MX; i++) {
        for(int j = i + 1; j < MX; j++) {
            for(int k = j + 1; k < MX; k++) {
                for(int l = k + 1; l < MX; l++) {
                    calculate(i, j, k, l);
                }
            }
        }
    }
}
