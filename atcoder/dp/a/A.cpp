#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

ll dp[100010];

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            dp[i] = dp[i] + abs(v[i - 1] - v[i]);
        } else {
            dp[i] = min(dp[i - 1] + abs(v[i - 1] - v[i]),
                        dp[i - 2] + abs(v[i - 2] - v[i]));
        }
    }
    cout << dp[n - 1] << endl;
}