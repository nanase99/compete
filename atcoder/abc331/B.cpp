#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N, S, M, L;
    cin >> N >> S >> M >> L;
    ll ans = LONG_MAX;

    rep(i, N / 6 + 2) {
        rep(j, N / 8 + 2) {
            rep(k, N / 12 + 2) {
                if (i * 6 + j * 8 + k * 12 >= N)
                    ans = min(i * S + j * M + k * L, ans);
            }
        }
    }

    cout << ans << endl;
}