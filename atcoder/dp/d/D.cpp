#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll dp[110][100010];

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> input(n);
    rep(i, n) cin >> input[i].first >> input[i].second;

    rep(i, n) {
        rep(j, w + 1) {
            auto [wi, vi] = input[i];
            chmax(dp[i + 1][j], dp[i][j]);
            if (j - wi < 0) continue;
            chmax(dp[i + 1][j], dp[i][j - wi] + vi);
        }
    }
    cout << dp[n][w] << endl;
}