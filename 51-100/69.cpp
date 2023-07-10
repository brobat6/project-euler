#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
static int p[N];

int main() {
    for(int i = 0; i < N; i++) p[i] = i;
    for(int i = 2; i < N; i++) if(p[i] == i) for(int j = i; j < N; j += i) p[j] -= p[j] / i;
    double mx = 0;
    int ans = 0;
    for(int i = 2; i < N; i++) {
        if(1.0 * i / p[i] > mx) {
            mx = 1.0 * i / p[i];
            ans = i;
        }
    }
    cout << ans << ' ' << mx << '\n'; 
}
