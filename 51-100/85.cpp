#include <bits/stdc++.h>
using namespace std;

int main() {
    // m * (m + 1) * n * (n + 1) / 4
    long long target = 2000000;
    for(int n = 1; n <= 2000; n++) {
        for(int m = 1; m <= 2000; m++) {
            long long area = 1ll * n * (n + 1) * m * (m + 1) / 4ll;
            if(abs(area - target) <= 10) {
                cout << n << ' ' << m << ' ' << area << ' ' << n * m << '\n';
            }
        }
    }
}
