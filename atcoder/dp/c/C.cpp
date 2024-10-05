#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
ll dp[100010][3];
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<vector<ll>> plans = vector(n, vector<ll>(3, 0));

    rep(i, n) rep(j, 3) cin >> plans[i][j];

    rep(i, n) {
        rep(j, 3) {
            rep(k, 3) {
                if (j == k) continue;
                // dp[i][j]:
                // i日目にjの行動(i-1日目にとった行動kに対してj!=k)をとった場合の最大の幸福値
                chmax(dp[i + 1][j], dp[i][k] + plans[i][j]);
            }
        }
    }
    ll ans = 0;
    rep(i, 3) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}