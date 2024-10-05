#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

bool isOK(ll x, const vector<pair<ll, ll>>& v) {
    vector<ll> t;
    repc(e, v) {
        if (x - e.first < 0) return false;
        t.push_back((x - e.first) / e.second);
    }
    sort(all(t));

    rep(i, t.size()) {
        if (t[i] < i) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;

    ll ng = min_element(all(v))->first - 1;
    ll ok = 1LL << 60;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid, v))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
}