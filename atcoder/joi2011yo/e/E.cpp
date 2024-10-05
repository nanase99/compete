#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int h, w, n;

int bfs(vector<vector<char>>& v, pair<int, int> start) {
    queue<pair<pair<int, int>, int>> q;
    int hp = 1;
    q.push({start, 0});
    int ans = 0;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [pos, time] = q.front();
        q.pop();
        if (v[pos.first][pos.second] == '0' + hp) {
            q = queue<pair<pair<int, int>, int>>();
            visited = vector(h, vector<bool>(w, false));
            visited[pos.first][pos.second] = true;
            if (hp++ == n) {
                ans = time;
                break;
            }
            q.push({pos, time});
        }
        rep(i, 4) {
            auto [y, x] = pos;
            auto nextY = y + dy[i];
            auto nextX = x + dx[i];
            if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w) continue;
            if (v[nextY][nextX] == 'X') continue;
            if (visited[nextY][nextX]) continue;
            visited[nextY][nextX] = true;
            q.push({{nextY, nextX}, time + 1});
        }
    }

    return ans;
}

int main() {
    cin >> h >> w >> n;
    vector<vector<char>> v(h, vector<char>(w));
    pair<int, int> start;
    rep(i, h) {
        string tmp;
        cin >> tmp;
        rep(j, w) {
            char c = tmp[j];
            v[i][j] = c;
            if (c == 'S') start = {i, j};
        }
    }
    int ans = bfs(v, start);
    cout << ans << endl;
}