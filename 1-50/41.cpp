#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int check(int digits) {
    vector <int> p(digits);
    iota(p.begin(), p.end(), 1);
    vector <int> pan;
    do {
        int v = 0;
        int m = 1;
        for(auto i : p) {
            v += i * m;
            m *= 10;
        }
        pan.push_back(v);
    } while(next_permutation(p.begin(), p.end()));
    sort(pan.begin(), pan.end(), greater<int>());
    for(auto pr : pan) {
        if(is_prime(pr)) {
            return pr;
        }
    }
    return 0;
}

int main() {
    for(int i = 9; i > 0; i--) {
        int x = check(i);
        if(x > 0) {
            cout << x << '\n';
            break;
        }
        cout << "No " << i << " digit pandigital prime!\n";
    }
}
