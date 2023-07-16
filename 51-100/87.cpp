#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int N = 10000;
	int M = 50000001;
	vector <int> pr, lp(N);
	iota(lp.begin(), lp.end(), 0);
	for(int i = 2; i < N; i++) if(lp[i] == i) for(int j = i * i; j < N; j += i) lp[j] = i;
	for(int i = 2; i < N; i++) if(lp[i] == i) pr.push_back(i);

	vector<vector<int>> pos(4, vector<int>(M, false));
	pos[0][0] = true;
	for(int i = 0; i < 3; i++) {
		vector <int> p;
		for(auto j : pr) {
			int x = 1;
			if(i == 0) x = j * j;
			if(i == 1) x = j * j * j;
			if(i == 2) x = j * j * j * j;
			if(x < M) p.push_back(x);
		}
		for(int j = 0; j < M; j++) {
			if(pos[i][j] == 0) continue;
			for(auto k : p) {
				if(j + k < M) pos[i + 1][j + k] = true;
				else break;
			}
		}
	}
	cout << accumulate(pos[3].begin(), pos[3].end(), 0ll) << '\n';
}
