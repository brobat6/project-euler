#include <bits/stdc++.h>
using namespace std;

class PathSum {
public:
    vector<vector<int>> grid;
    vector<pair<int, int>> dir;
    pair<int, int> start;
    pair<int, int> end;

    int dijkstra() {
        int n = grid.size();
        int m = grid.front().size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1E9));
        dist[start.first][start.second] = grid[start.first][start.second];
        pq.push({-dist[start.first][start.second], start});
        while(!pq.empty()) {
            int curr_dist = pq.top().first * -1;
            pair<int, int> curr = pq.top().second;
            pq.pop();
            if(dist[curr.first][curr.second] != curr_dist) continue;
            for(auto k : dir) {
                int x = curr.first + k.first;
                int y = curr.second + k.second;
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                int next_dist = curr_dist + grid[x][y];
                if(next_dist < dist[x][y]) {
                    pq.push({-next_dist, {x, y}});
                    dist[x][y] = next_dist;
                }
            }
        }
        return dist[end.first][end.second];
    }
};

int main() {
    // Input
    int g[82][82];
    memset(g, 0, sizeof(g));
    for(int i = 1; i <= 80; i++) {
        string s;
        getline(cin, s);
        int c = 0;
        int it = 1;
        for(auto j : s) {
            if(j == ',') {
                g[i][it] = c;
                c = 0;
                it++;
            } else {
                int b = j - '0';
                c = c * 10 + b;
            }
        }
        g[i][it] = c;
        assert(it == 80);
    }

    PathSum ps;

    // Problem 81
    ps.grid.clear();
    ps.grid.resize(80, vector<int>(80));
    for(int i = 0; i < 80; i++) {
        for(int j = 0; j < 80; j++) {
            ps.grid[i][j] = g[i + 1][j + 1];
        }
    }
    ps.dir = {{1, 0}, {0, 1}};
    ps.start = {0, 0};
    ps.end = {79, 79};
    cout << ps.dijkstra() << '\n';

    // Problem 82
    ps.grid.clear();
    ps.grid.resize(80, vector<int>(82));
    for(int i = 0; i < 80; i++) {
        ps.grid[i][0] = 0;
        ps.grid[i][81] = 0;
        for(int j = 1; j <= 80; j++) {
            ps.grid[i][j] = g[i + 1][j];
        }
    }
    ps.dir = {{1, 0}, {-1, 0}, {0, 1}};
    ps.start = {0, 0};
    ps.end = {0, 81};
    cout << ps.dijkstra() << '\n';

    // Problem 83
    ps.grid.clear();
    ps.grid.resize(80, vector<int>(80));
    for(int i = 0; i < 80; i++) {
        for(int j = 0; j < 80; j++) {
            ps.grid[i][j] = g[i + 1][j + 1];
        }
    }
    ps.dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    ps.start = {0, 0};
    ps.end = {79, 79};
    cout << ps.dijkstra() << '\n';
}
