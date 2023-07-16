#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
	ld T = 3.0/7;
	int D = 1000000;
	ld diff = 1.0;
	int num, den;
	for(int i = 10; i <= D; i++) {
		// Binary search. 
		int L = 1;
		int R = i - 1;
		int pos_ans = -1;
		while(L <= R) {
			int M = (L + R)/2;
			ld x = M*1.0/i;
			if(x < T) {
				pos_ans = M;
				L = M + 1;
			} else {
				R = M - 1;
			}
		}
		ld pos_diff = T - pos_ans*1.0/i;
		if(pos_diff < diff) {
			diff = pos_diff;
			num = pos_ans;
			den = i;
		}	
	}
	cout << num << ' ' << den << '\n';
}
