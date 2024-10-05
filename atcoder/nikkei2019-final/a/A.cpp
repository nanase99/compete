#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n), sum;
    rep(i, n) cin >> v[i];

    rep(i, n) {
        if (i == 0) {
            sum.push_back(v[i]);
        } else {
            sum.push_back(v[i] + sum[i - 1]);
        }
    }

    for (int k = 1; k <= n; k++) {
        ll ans = 0LL;
        for (int i = k - 1; i < n; i++) {
            if (i - k < 0)
                ans = max(ans, sum[i]);
            else
                ans = max(ans, sum[i] - sum[i - k]);
        }
        cout << ans << endl;
    }
}