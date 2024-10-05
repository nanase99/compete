#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N, M, L;
    cin >> N >> M >> L;
    vector<pair<ll, ll>> A(N), B(M);

    set<pair<ll, ll>> cd;

    rep(i, N) {
        ll in;
        cin >> in;
        A[i] = {i + 1, in};
    }
    rep(i, M) {
        ll in;
        cin >> in;
        B[i] = {i + 1, in};
    }
    rep(i, L) {
        ll c, d;
        cin >> c >> d;
        cd.insert({c, d});
    }

    sort(all(A), [](auto&& a, auto&& b) { return a.second > b.second; });
    sort(all(B), [](auto&& a, auto&& b) { return a.second > b.second; });
    ll ans = 0;

    auto copy = cd;
    repc(ai, A) {
        repc(bi, B) {
            if (!cd.contains({ai.first, bi.first})) {
                ans = max(ai.second + bi.second, ans);
                break;
            }
        }
    }

    cout << ans << endl;
}