#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int curr = 0;
    do {
        curr++;
        if(curr == 1000000) {
            break;
        }
    } while(next_permutation(p.begin(), p.end()));
    for(auto i : p) cout << i;
    cout << '\n';
}
