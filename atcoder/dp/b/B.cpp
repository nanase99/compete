#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

ll dp[200010];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<vector<string>> aaa = vector(n, vector<string>());

    repc(a, h) aaa[0].push_back(to_string(a));
    repc(hoge, aaa[0]) {
        cout << hoge << endl;
    }

    rep(i, n) dp[i] = 1LL << 60;

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            dp[i] = min(dp[i], dp[i - j] + abs(h[i - j] - h[i]));
        }
    }
    cout << dp[n - 1] << endl;
}