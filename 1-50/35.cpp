#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;

vector<int> lp;
map<int, bool> pr;

bool check(string &s) {
    char c = s[0];
    for(int i = 1; i < (int)s.size(); i++) {
        s[i - 1] = s[i];
    }
    s[(int)s.size() - 1] = c;
    return pr[stoi(s)];
}

int main() {
    lp.resize(N);
    iota(lp.begin(), lp.end(), 0);
    for(int i = 2; i < N; i++) {
        if(lp[i] == i) {
            pr[i] = true;
            for(long long j = 1ll * i * i; j < N; j += i) {
                lp[j] = min(lp[j], i);
            }
        }
    }
    int ans = 0;
    for(auto i : pr) {
        string s = to_string(i.first);
        bool pos = true;
        for(int i = 0; i < (int)s.length(); i++) {
            pos &= check(s);
        }
        ans += pos;
    }
    cout << ans << '\n';
}
