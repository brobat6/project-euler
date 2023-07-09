#include <bits/stdc++.h>
using namespace std;

/**
 * Brute force. 
*/
int main() {
    vector<int> sol(1001, 0);
    for(int i = 1; i <= 1000; i++) {
        for(int j = i; j <= 1000 - i; j++) {
            for(int k = j; k <= 1000 - i - j; k++) {
                if(i * i + j * j == k * k) {
                    sol[i + j + k]++;
                }
            }
        }
    }
    int mx = 0;
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        if(sol[i] > mx) {
            ans = i;
            mx = sol[i];
        }
    }
    cout << ans << '\n';
}
