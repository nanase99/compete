#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int N, S, K;
    cin >> N >> S >> K;
    vector<pair<int, int> > p(N);
    rep(i, N) cin >> p[i].first >> p[i].second;

    ll ans = 0;

    repc(e, p) {
        ans += e.first * e.second;
    }

    if (ans < S) {
        ans += K;
    }

    cout << ans << endl;
}