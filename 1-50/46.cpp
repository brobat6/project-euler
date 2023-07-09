#include <bits/stdc++.h>
using namespace std;

map<int, bool> prime;
vector <int> square;

int main() {
    {
        int n = 10000;
        vector <int> lp(n);
        iota(lp.begin(), lp.end(), 0);
        for(int i = 2; i < n; i++) {
            if(lp[i] == i) {
                prime[i] = true;
                for(int j = i * i; j < n; j += i) {
                    lp[j] = i;
                }
            }
        }
    }
    for(int i = 0; i <= 1000; i++) {
        square.push_back(2 * i * i);
    }
    vector <bool> can(2100000, false);
    for(auto p : prime) {
        for(auto q : square) {
            can[p.first + q] = true; 
        }
    }
    for(int i = 9; i < (int)can.size(); i += 2) {
        if(!can[i]) {
            cout << i << '\n';
            return 0;
        }
    }
}
