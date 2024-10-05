#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int r, c;
int sx, sy, gx, gy;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int ans = -1;

vector<vector<int>> bfs(vector<vector<char>>& v) {
    queue<pair<int, int>> q;
    q.push({sy - 1, sx - 1});
    vector<vector<int>> ans(r, vector<int>(c, -1));
    ans[sy - 1][sx - 1] = 0;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        rep(i, 4) {
            auto nextY = y + dy[i];
            auto nextX = x + dx[i];

            if (v[nextY][nextX] == '#') continue;
            if (ans[nextY][nextX] != -1) continue;

            q.push({nextY, nextX});
            ans[nextY][nextX] = ans[y][x] + 1;
        }
    }

    return ans;
}

int main() {
    cin >> r >> c >> sy >> sx >> gy >> gx;
    vector<vector<char>> v(r, vector<char>(c));

    rep(i, r) rep(j, c) cin >> v[i][j];

    auto ans = bfs(v);

    cout << ans[gy - 1][gx - 1] << endl;
}