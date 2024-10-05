#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<pair<ll, ll>> st(n);

    rep(i, n) cin >> v[i];
    rep(i, n - 1) cin >> st[i].first >> st[i].second;

    rep(i, n - 1) {
        auto [from, to] = st[i];
        auto nextCoin = (v[i] / from) * to;
        v[i + 1] += nextCoin;
    }

    cout << v[n - 1] << endl;
}