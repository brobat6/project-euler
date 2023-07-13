#include <bits/stdc++.h>
using namespace std;

int ans;
bool solved;
bool pos[9][9][9]; // pos[i][j][k] --> It is possible to have k in (i, j).
stack<array<int, 3>> st;

inline int row(int x) {
    return x / 9;
}

inline int col(int x) {
    return x % 9;
}

inline int box(int x) {
    return (row(x) < 3 ? 0 : (row(x) < 6 ? 1 : 2)) * 3 + (col(x) < 3 ? 0 : (col(x) < 6 ? 1 : 2));
}

inline int cell(int r, int c) {
    return r * 9 + c;
}

int add(int rr, int cc, int v, bool add_to_stack = true) {
    // Make it more optimized (requires some effort)
    // 81 ops right now, can be changed to 27 ops 
    int added = 0;
    int p = cell(rr, cc);
    for(int a = 0; a < 9; a++) {
        for(int b = 0; b < 9; b++) {
            int q = cell(a, b);
            if(p == q) {
                for(int c = 0; c < 9; c++) {
                    if(c != v && pos[a][b][c]) {
                        pos[a][b][c] = false;
                        if(add_to_stack) {
                            st.push({a, b, c});
                            added++;
                        }
                    }
                }
            } else if(row(p) == row(q) || col(p) == col(q) || box(p) == box(q)) {
                if(pos[a][b][v]) {
                    pos[a][b][v] = false;
                    if(add_to_stack) {
                        st.push({a, b, v});
                        added++;
                    }
                }
            }
        }
    }
    return added;
}

void debug() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            for(int k = 0; k < 9; k++) {
                cout << pos[i][j][k];
            }
            cout << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

bool check() {
    vector <int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<int>> check_row(9), check_col(9), check_box(9);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            vector <int> p;
            for(int k = 0; k < 9; k++) {
                if(pos[i][j][k]) {
                    p.push_back(k);
                }
            }
            if((int)p.size() != 1) return false;
            check_row[row(cell(i, j))].push_back(p.front());
            check_col[col(cell(i, j))].push_back(p.front());
            check_box[box(cell(i, j))].push_back(p.front());
        }
    }
    for(auto i : check_row) {
        sort(i.begin(), i.end());
        if(i != p) return false;
    }
    for(auto i : check_col) {
        sort(i.begin(), i.end());
        if(i != p) return false;
    }
    for(auto i : check_box) {
        sort(i.begin(), i.end());
        if(i != p) return false;
    }
    return true;
}

void remove(int k = 1) {
    for(int i = 0; i < k; i++) {
        assert(!st.empty());
        auto t = st.top();
        st.pop();
        pos[t[0]][t[1]][t[2]] ^= 1;
    }
}

void solve(int i, int j) {
    if(solved) return;
    for(int k = 0; k < 9; k++) {
        if(pos[i][j][k]) {
            int added = add(i, j, k);
            if(check()) {
                solved = true;
                return;
            }
            int c = cell(i, j);
            if(c == 80) return;
            solve(row(c + 1), col(c + 1));
            if(solved) return;
            remove(added);
        }
    }
}

int main() {
    ans = 0;
    int T = 50;
    while(T--) {
        string s;
        cin >> s >> s;
        memset(pos, true, sizeof(pos));
        solved = false;
        while(!st.empty()) st.pop();
        char c;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> c;
                int x = c - '0';
                if(x == 0) continue;
                x--;
                add(i, j, x, false);
            }
        }
        solve(0, 0);
        assert(solved);
        for(int j = 0; j < 3; j++) for(int k = 0; k < 9; k++) {
            ans += pos[0][j][k] * (k + 1) * (j == 0 ? 100 : (j == 1 ? 10 : 1));
        }
        cout << "Solved Grid " << s << "!\n";
    }
    cout << ans << '\n';
}
