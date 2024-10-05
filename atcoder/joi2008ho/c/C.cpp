#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> v(N);
    rep(i, N) cin >> v[i];
    v.push_back(0);

    set<ll> s;

    ll ans = 0;
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            ll pairSum = v[i] + v[j];
            if (pairSum < M) {
                s.insert(-pairSum);
            }
        }
    }
    repc(e, s) {
        ll remain = M + e;
        auto find = s.lower_bound(-remain);
        if (find != s.end()) {
            remain += *find;
        }
        ans = max(ans, M - remain);
    }
    cout << ans << endl;
}