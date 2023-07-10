#include <bits/stdc++.h>
using namespace std;

const int N = 10000001;
static int p[N];

bool is_permutation(int x, int y) {
    vector <int> p, q;
    while(x > 0) {
        p.push_back(x % 10);
        x /= 10;
    }
    while(y > 0) {
        q.push_back(y % 10);
        y /= 10;
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    return p == q;
}

int main() {
    for(int i = 0; i < N; i++) p[i] = i;
    for(int i = 2; i < N; i++) if(p[i] == i) for(int j = i; j < N; j += i) p[j] -= p[j] / i;
    double mx = 100.0;
    int ans = 0;
    for(int i = 2; i < N; i++) {
        if(is_permutation(i, p[i])) {
            if(i * 1.0 / p[i] < mx) {
                ans = i;
                mx = i * 1.0 / p[i];
            }
        }
    }
    cout << ans << ' ' << p[ans] << ' ' << mx << '\n';
}
