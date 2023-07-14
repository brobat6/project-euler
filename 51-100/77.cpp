#include<bits/stdc++.h>
using namespace std;

int main() {
    int N = 201;
    vector <int> pr;
    vector <int> lp(N);
    iota(lp.begin(), lp.end(), 0);
    for(int i = 2; i < N; i++) if(lp[i] == i) {
        pr.push_back(i);
        for(int j = i*i; j < N; j += i) lp[j] = min(lp[j], i);
    }
    // dp[i] ---> Number of ways to make i. 
    vector<int> dp(N, 0);
    dp[0] = 1;
    for(int i = 0; i < (int)pr.size(); i++) {
        for(int j = pr[i]; j < N; j++) {
            dp[j] += dp[j - pr[i]];
        }
    }
    for(int i = 0; i < N; i++) {
        if(dp[i] >= 5000) {
            cout << i << '\n';
            return 0;
        }
    }
}
