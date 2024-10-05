#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll m, n;
    cin >> m;
    vector<pair<ll, ll>> M, N;

    rep(i, m) {
        ll mx, my;
        cin >> mx >> my;
        M.push_back({mx, my});
    }

    cin >> n;
    rep(i, n) {
        ll nx, ny;
        cin >> nx >> ny;
        N.push_back({nx, ny});
    }

    sort(all(M), [](auto&& a, auto&& b) { return a.first < b.first; });
    sort(all(N), [](auto&& a, auto&& b) { return a.first < b.first; });

    vector<pair<ll, ll>> dist;
    for (auto itr = M.begin() + 1; itr != M.end(); ++itr) {
        dist.push_back(
            {itr->first - M.begin()->first, itr->second - M.begin()->second});
    }
    repc(e, N) {
        bool flg = true;
        repc(target, dist) {
            pair<ll, ll> candidate = {e.first + target.first,
                                      e.second + target.second};
            if (find(all(N), candidate) == N.end()) {
                flg = false;
                break;
            }
        }
        if (flg) {
            pair<ll, ll> ans = {e.first - M.begin()->first,
                                e.second - M.begin()->second};

            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}