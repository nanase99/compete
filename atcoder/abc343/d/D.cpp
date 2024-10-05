#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n, t;
    cin >> n >> t;
    vector<pair<ll, ll>> v(t);

    rep(i, t) {
        cin >> v[i].first >> v[i].second;
    }

    map<ll, int> s;
    map<int, ll> m;
    rep(i, n) {
        m[i] = 0LL;
    }
    s[0] = n;

    repc(e, v) {
        auto [id, point] = e;
        id--;
        s[m[id]]--;
        if (s[m[id]] == 0) s.erase(m[id]);
        m[id] += point;
        s[m[id]]++;
        cout << s.size() << endl;
    }
}