#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> jv(m, vector<int>(n)), ov(m, vector<int>(n)),
        iv(m, vector<int>(n)), sumj(m + 1, vector<int>(n + 1)),
        sumo(m + 1, vector<int>(n + 1)), sumi(m + 1, vector<int>(n + 1));
    vector<vector<int>> K(k, vector<int>(4));
    rep(i, m) rep(j, n) {
        char c;
        cin >> c;
        if (c == 'J') {
            jv[i][j] = 1;
        } else if (c == 'O') {
            ov[i][j] = 1;
        } else {
            iv[i][j] = 1;
        }
    };
    rep(i, k) rep(j, 4) cin >> K[i][j];

    // 横
    rep(i, m) rep(j, n) sumj[i + 1][j + 1] = sumj[i + 1][j] + jv[i][j];
    rep(i, m) rep(j, n) sumo[i + 1][j + 1] = sumo[i + 1][j] + ov[i][j];
    rep(i, m) rep(j, n) sumi[i + 1][j + 1] = sumi[i + 1][j] + iv[i][j];

    // 縦
    rep(i, m) rep(j, n) sumj[i + 1][j + 1] += sumj[i][j + 1];
    rep(i, m) rep(j, n) sumo[i + 1][j + 1] += sumo[i][j + 1];
    rep(i, m) rep(j, n) sumi[i + 1][j + 1] += sumi[i][j + 1];

    rep(i, k) {
        int a, b, c, d;
        a = K[i][0];
        b = K[i][1];
        c = K[i][2];
        d = K[i][3];

        auto ansj =
            sumj[c][d] - sumj[a - 1][d] - sumj[c][b - 1] + sumj[a - 1][b - 1];
        auto anso =
            sumo[c][d] - sumo[a - 1][d] - sumo[c][b - 1] + sumo[a - 1][b - 1];
        auto ansi =
            sumi[c][d] - sumi[a - 1][d] - sumi[c][b - 1] + sumi[a - 1][b - 1];

        printf("%d %d %d\n", ansj, anso, ansi);
    }
}