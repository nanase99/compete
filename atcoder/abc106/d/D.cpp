#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> s(n + 1, 0);
    map<int, int> mp;
    map<int, vector<int>> mv, sm;
    rep(i, n + 1) {
        mv[i] = vector(n + 1, 0);
    }
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        r--;
        rep(j, l + 1) mv[j][r]++;
    }

    repc(e, mv) {
        auto [l, v] = e;
        sm[l] = vector<int>(n + 1, 0);
        rep(i, n) {
            sm[l][i + 1] = sm[l][i] + v[i];
        }
    }

    for (; q--;) {
        int p, q;
        cin >> p >> q;
        cout << sm[p][q] << "\n";
    }
}