#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int dp[110][10010];

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> v(N), w(N);

    rep(i, N) {
        cin >> v[i] >> w[i];
    }

    rep(i, N + 1) {
        rep(j, W + 1) {
            chmax(dp[i + 1][j], dp[i][j]);
            if (j - w[i] >= 0) chmax(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
        }
    }
    cout << dp[N][W] << endl;
}