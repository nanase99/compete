#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> v(h, vector<char>(w));
    map<pair<int, int>, bool> seen;
    map<int, int> steps;
    int ans = w * h - 1;
    rep(i, h) {
        string in;
        cin >> in;
        rep(j, w) {
            char c = in[j];
            v[i][j] = c;
            if (c == '#') {
                ans--;
            }
        }
    }

    bool isGoal = false;
    int goalDepth = INT_MAX;

    auto bfs = [&]() -> void {
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        seen[{0, 0}] = true;
        while (!q.empty()) {
            auto [pos, depth] = q.front();
            auto [y, x] = pos;
            q.pop();
            if (y == h - 1 && x == w - 1) {
                ans -= depth;
                isGoal = true;
                break;
            }

            rep(i, 4) {
                auto nextY = y + dy[i];
                auto nextX = x + dx[i];
                if (nextY < 0 || nextY >= h || nextX < 0 || nextX >= w)
                    continue;
                if (v[nextY][nextX] == '#') continue;
                if (seen[{nextY, nextX}]) continue;
                seen[{nextY, nextX}] = true;
                q.push({{nextY, nextX}, depth + 1});
            }
        }
    };

    bfs();

    if (isGoal)
        cout << ans << endl;
    else
        cout << -1 << endl;
}