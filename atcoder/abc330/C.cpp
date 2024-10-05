#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll D;
    cin >> D;
    ll ans = LONG_MAX;

    rep(i, (int)sqrt(D) + 1) {
        for (int j = 0; j <= (int)sqrt(D) + 1; j++) {
            ll num = i * i + j * j;
            ans = min(ans, abs(D - num));
        }
    }

    cout << ans << endl;
}