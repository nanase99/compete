#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    rep(i, n) cin >> C[i];
    sort(all(A));
    sort(all(B));
    sort(all(C));

    map<int, int> m;

    ll ans = 0;

    repc(e, B) {
        auto Anum = lower_bound(all(A), e) - A.begin();
        auto Cnum = C.size() - (upper_bound(all(C), e) - C.begin());
        ans += Anum * Cnum;
    }

    cout << ans << endl;
}
