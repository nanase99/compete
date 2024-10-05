#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> storePos(n), deliverPos(m);

    rep(i, n - 1) cin >> storePos[i];
    rep(i, m) cin >> deliverPos[i];
    sort(all(storePos));
    storePos.push_back(d);
    ll ans = 0;

    rep(i, m) {
        ll localAns = LONG_MAX;
        // itrからindexへの変換を考慮する
        auto index =
            lower_bound(all(storePos), deliverPos[i]) - storePos.begin();
        localAns = abs(storePos[index] - deliverPos[i]);
        if (index != 0) {
            localAns = min(localAns, abs(storePos[index - 1] - deliverPos[i]));
        }
        ans += localAns;
    }
    cout << ans << endl;
}