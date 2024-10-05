#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
ll ans;
ll dp[100000];

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> stages(n - 1, vector<ll>(4));
    rep(i, n - 1) {
        rep(j, 3) {
            cin >> stages[i][j];
        }
        stages[i][3] = i;
    }
    sort(all(stages), [](auto a, auto b) { return a[2] < b[2]; });
    multimap<ll, ll> m;

    for (ll i = 0; i < n - 1; i++) {
        ans += stages[i][0];
        m.emplace(stages[i][2] - 1, i);
    }
    dp[0] = 0LL;

    for (int ind = 0; ind < stages.size(); ind++) {
        ll local = LONG_MAX;
        int i = stages[ind][3];
        auto [first, second] = m.equal_range(i);
        for (auto itr = first; itr != second; ++itr) {
            auto [to, from] = *itr;
            ll res = dp[from] + stages[from][1];
            local = min(res, local);
        }
        dp[i] = min(dp[i - 1] + stages[i - 1][0], local);
    }
    cout << dp[n - 1] << endl;
}