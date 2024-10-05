#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int w, h;

int dxEven[] = {0, 1, -1, 1, 0, 1};
int dyEven[] = {-1, -1, 0, 0, 1, 1};
int dxOdd[] = {-1, 0, -1, 1, -1, 0};
int dyOdd[] = {-1, -1, 0, 0, 1, 1};

int main() {
    cin >> w >> h;

    vector<vector<int>> v(h + 2, vector<int>(w + 2, 0));
    vector<vector<bool>> seen(h + 2, vector<bool>(w + 2, false));

    rep(i, h) rep(j, w) {
        int in;
        cin >> in;
        v[i + 1][j + 1] = in;
    }
    int sum = 0;

    auto bfs = [&]() -> void {
        queue<pair<int, int>> q;
        q.push({0, 0});
        seen[0][0] = true;

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            if ((y + 1) % 2 == 1) {
                rep(i, 6) {
                    auto newX = x + dxOdd[i];
                    auto newY = y + dyOdd[i];
                    if (newX < 0 || newX > w + 1 || newY < 0 || newY > h + 1)
                        continue;
                    if (v[newY][newX] == 1)
                        sum++;
                    else if (!seen[newY][newX]) {
                        seen[newY][newX] = true;
                        q.push({newY, newX});
                    }
                }
            } else {
                rep(i, 6) {
                    auto newX = x + dxEven[i];
                    auto newY = y + dyEven[i];
                    if (newX < 0 || newX > w + 1 || newY < 0 || newY > h + 1)
                        continue;
                    if (v[newY][newX] == 1)
                        sum++;
                    else if (!seen[newY][newX]) {
                        seen[newY][newX] = true;
                        q.push({newY, newX});
                    }
                }
            }
        }
    };

    bfs();

    cout << sum << endl;
}