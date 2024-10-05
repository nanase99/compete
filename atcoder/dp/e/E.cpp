#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n, w;
    int maxValue = 100100;
    cin >> n >> w;
    vector<pair<int, int>> v(n);
    vector<vector<ll>> dp(110, vector<ll>(100100, INF));

    rep(i, n) cin >> v[i].first >> v[i].second;

    dp[0][0] = 0;

    rep(i, n) {
        rep(j, maxValue) {
            auto [wi, vi] = v[i];
            chmin(dp[i + 1][j], dp[i][j]);
            if (j - vi < 0) continue;
            chmin(dp[i + 1][j], dp[i][j - vi] + wi);
        }
    }

    int ans = 0;
    rep(i, n + 1) {
        rep(j, maxValue) {
            if (dp[i][j] <= w) chmax(ans, j);
        }
    }

    cout << ans << endl;
}