#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int h, w;
    ll k, v;
    cin >> h >> w >> k >> v;
    vector<vector<ll>> mp(h, vector<ll>(w)), s(h + 1, vector<ll>(w + 1, 0));
    rep(i, h) rep(j, w) cin >> mp[i][j];
    int ans = 0;

    rep(i, h) rep(j, w) s[i + 1][j + 1] =
        s[i][j + 1] + s[i + 1][j] - s[i][j] + mp[i][j];

    for (int i1 = 0; i1 <= h; i1++) {
        for (int j1 = 0; j1 <= w; j1++) {
            for (int i2 = i1 + 1; i2 <= h; i2++) {
                for (int j2 = j1 + 1; j2 <= w; j2++) {
                    ll cost = s[i2][j2] - s[i2][j1] - s[i1][j2] + s[i1][j1];
                    if (cost == 0) continue;
                    cost += ((i2 - i1) * (j2 - j1)) * k;
                    if (cost <= v) {
                        ans = max((i2 - i1) * (j2 - j1), ans);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}