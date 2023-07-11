#include <bits/stdc++.h>
using namespace std;
#define int long long

map<vector<int>, vector<int>> c;

int32_t main() {
    for(int i = 1; i <= 10000; i++) {
        int x = i * i * i;
        vector <int> cnt(10, 0);
        while(x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        c[cnt].push_back(i);
    }
    set <int> ans;
    for(auto i : c) {
        if((int)i.second.size() == 5) {
            bool pos = false;
            for(auto j : i.second) if(j == 5027) pos = true;
            for(auto j : i.second) {
                ans.insert(j);
                if(pos) cout << j << ',' << j * j * j << " ; ";
            }
            if(pos) cout << '\n';
        }
    }
    cout << (*ans.begin()) << '\n';
}
