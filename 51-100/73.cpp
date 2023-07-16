#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	int D = 12000;
	ld L = 1.0/3;
	ld U = 1.0/2;
	int ans = 0;
	for(int i = 1; i <= D; i++) {
		for(int j = i + 1; j <= D; j++) {
			if(__gcd(i, j) != 1) continue;
			ld X = i*1.0/j;
			if(X > L && X < U) ans++;
		}
	}
	cout << ans << '\n';
}
