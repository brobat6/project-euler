#include <bits/stdc++.h>
using namespace std;

map<int, bool> prime;

int main() {
    {
        int n = 10000;
        vector <int> lp(n);
        iota(lp.begin(), lp.end(), 0);
        for(int i = 2; i < n; i++) {
            if(lp[i] == i) {
                if(i >= 1000) prime[i] = true;
                for(int j = i * i; j < n; j += i) {
                    lp[j] = i;
                }
            }
        }
    }
    for(auto p : prime) {
        if(prime.find(p.first + 3330) != prime.end() && prime.find(p.first + 6660) != prime.end()) {
            cout << p.first << ' ' << p.first + 3330 << ' ' << p.first + 6660 << '\n';
        }
    }
    // 2969 6299 9629
}
