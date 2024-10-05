#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> v(h);
    rep(i, h) {
        string s;
        cin >> s;
        repc(c, s) v[i].push_back(c);
    }

    vector<pair<ll, ll>> vCol(w, {0LL, 0LL}), vRow(h, {0LL, 0LL});

    rep(i, h) {
        ll dotCounter = 0LL;
        ll circleCounter = 0LL;
        rep(j, w) {
            if (v[i][j] == '.') {
                vRow[i].second = max(circleCounter, vRow[i].second);
                dotCounter++;
                circleCounter = 0LL;
            } else if (v[i][j] == 'o') {
                vRow[i].second++;
            } else if (v[i][j] == 'x') {
                vRow[i].first = max(dotCounter, vRow[i].first);
                vRow[i].second = max(circleCounter, vRow[i].second);
                dotCounter = 0LL;
                circleCounter = 0LL;
            }
        }
        vRow[i].first = max(dotCounter, vRow[i].first);
        vRow[i].second = max(circleCounter, vRow[i].second);
    }

    rep(i, w) {
        ll dotCounter = 0LL;
        ll circleCounter = 0LL;
        rep(j, h) {
            if (v[j][i] == '.') {
                vCol[i].second = max(circleCounter, vCol[i].second);
                dotCounter++;
                circleCounter = 0LL;
            } else if (v[j][i] == 'o') {
                circleCounter++;
            } else if (v[j][i] == 'x') {
                vCol[i].first = max(dotCounter, vCol[i].first);
                vCol[i].second = max(circleCounter, vCol[i].second);
                dotCounter = 0LL;
                circleCounter = 0LL;
            }
        }
        vCol[i].first = max(dotCounter, vCol[i].first);
        vCol[i].second = max(circleCounter, vCol[i].second);
    }

    ll ans = LONG_MAX;
    bool flg = false;
    repc(e, vCol) {
        auto [dot, circle] = e;
        if (circle >= k) {
            cout << 0 << endl;
            return 0;
        }
        if (dot + circle >= k) {
            ans = min(k - circle, ans);
            flg = true;
        }
    }

    repc(e, vRow) {
        auto [dot, circle] = e;
        if (circle >= k) {
            cout << 0 << endl;
            return 0;
        }
        if (dot + circle >= k) {
            ans = min(k - circle, ans);
            flg = true;
        }
    }
    if (!flg)
        cout << -1 << endl;
    else
        cout << ans << endl;
}