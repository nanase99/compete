#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int h, n, w;
    cin >> h >> w >> n;
    vector<vector<char>> m(h, vector<char>(w));
    string s;
    cin >> s;
    rep(i, h) rep(j, w) cin >> m[i][j];

    int ans = 0;

    for (int i = 1; i < h - 1; i++) {
        for (int j = 1; j < w - 1; j++) {
            pair<int, int> pos = {i, j};
            if (m[pos.first][pos.second] == '#') {
                continue;
            }
            bool flg = true;
            repc(c, s) {
                if (c == 'L') {
                    pos.second = pos.second - 1;
                }
                if (c == 'R') {
                    pos.second = pos.second + 1;
                }
                if (c == 'U') {
                    pos.first = pos.first - 1;
                }
                if (c == 'D') {
                    pos.first = pos.first + 1;
                }

                if (m[pos.first][pos.second] == '#') {
                    flg = false;
                    break;
                }
            }
            if (flg) ans++;
        }
    }
    cout << ans << endl;
}