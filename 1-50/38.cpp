#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_pandigital(int x) {
    vector <int> p = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector <int> q;
    while(x > 0) {
        q.push_back(x % 10);
        x /= 10;
    }
    sort(q.begin(), q.end());
    return p == q;
}

map<int, bool> can;

int concatenate(int x, int y) {
    int z = y;
    int cnt = 1;
    while(z > 0) {
        cnt *= 10;
        z /= 10;
    }
    return x * cnt + y;
}

int length(int x) {
    int cnt = 0;
    while(x > 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}

int32_t main() {
    for(int i = 1; i < 10000; i++) {
        int ans = 0;
        for(int j = 1; j < 10; j++) {
            ans = concatenate(ans, i * j);
            if(length(ans) > 9) break;
            if(is_pandigital(ans)) can[ans] = true;
        }
    }
    int mx = 0;
    for(auto i : can) {
        mx = max(mx, i.first);
    }
    cout << mx << '\n';
}
