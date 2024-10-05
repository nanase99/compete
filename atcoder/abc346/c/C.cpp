#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    set<ll> v;
    rep(i, n) {
        ll tmp;
        cin >> tmp;
        v.insert(tmp);
    }
    ll ans = (k * (k + 1)) / 2;
    repc(n, v) {
        if (n >= 1 && n <= k) ans -= n;
    }
    cout << ans << endl;
}