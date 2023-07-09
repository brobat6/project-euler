#include <bits/stdc++.h>
using namespace std;

const int MX = 1001;
static int spiral[MX][MX];

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

int main() {
    memset(spiral, 0, sizeof(spiral));
    int cx = MX/2;
    int cy = MX/2;
    // Making anti-clockwise spiral for ease
    Direction dir = LEFT;
    int val = 1;
    while(cx >= 0 && cy >= 0 && cx < MX && cy < MX) {
        // cout << cx << ' ' << cy << ' ' << dir << ' ' << val << '\n';
        spiral[cx][cy] = val;
        val++;
        if(dir == LEFT) {
            if(cx == cy) {
                // Move out.
                cy--;
                dir = DOWN;
            } else {
                cy--;
            }
        } else if(dir == DOWN) {
            if(cx - MX/2 == MX/2 - cy) {
                dir = RIGHT;
                cy++;
            } else {
                cx++;
            }
        } else if(dir == RIGHT) {
            if(cx == cy) {
                dir = UP;
                cx--;
            } else {
                cy++;
            }
        } else {
            if(MX/2 - cx == cy - MX/2) {
                dir = LEFT;
                cy--;
            } else {
                cx--;
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < MX; i++) {
        for(int j = 0; j < MX; j++) {
            if(i == j || i + j == MX - 1) {
                ans += spiral[i][j];
            }
        }
    }
    cout << ans << '\n';
}
