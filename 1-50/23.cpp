#include <bits/stdc++.h>
using namespace std;

const int MX = 28500;

int main() {
    vector<vector<int>> f(MX);
    for(int i = 1; i < MX; i++) {
        for(int j = i * 2; j < MX; j += i) {
            f[j].push_back(i);
        }
    }
    vector <int> abundant;
    for(int i = 2; i < MX; i++) {
        int sum = accumulate(f[i].begin(), f[i].end(), 0);
        if(sum > i) {
            abundant.push_back(i);
        }
    }
    cout << (int)abundant.size() << '\n'; // 7054
    vector<bool> pos(MX, false);
    for(auto i : abundant) for(auto j : abundant) if(i + j < MX) pos[i + j] = true;
    long long ans = 0;
    for(int i = 0; i < MX; i++) {
        if(!pos[i]) ans += i;
    }
    cout << ans << '\n';
}
