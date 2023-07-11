#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1000001;
    vector <int> f(n, 0);
    for(int i = 1; i < n; i++) for(int j = i * 2; j < n; j+=i) f[j] += i;
    int ans = 0;
    set <int> v;
    for(int i = 2; i < n; i++) {
        int curr = i;
        set <int> t;
        int it = 200;
        bool pos = false;
        while(it > 0 && curr >= 2 && curr <= 1000000) {
            it--;
            t.insert(curr);
            curr = f[curr];
            if(curr == i) {
                pos = true;
                break;
            }
        }
        if((int)t.size() > ans && pos) {
            ans = t.size();
            v = t;
        }
    }
    cout << ans << '\n';
    for(auto i : v) cout << i << ' '; cout << '\n';
}
