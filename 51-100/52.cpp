#include <bits/stdc++.h>
using namespace std;

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
    for(int i = 1; ; i++) {
        bool pos = true;
        for(int j = 6; j > 1; j--) {
            if(is_permutation(i, i * j)) continue;
            pos = false;
            break;
        }
        if(pos) {
            cout << i << '\n';
            break;
        }
    }
}
