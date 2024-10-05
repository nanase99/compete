#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(1e7), s(1e7);

    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        a++;
        b++;
        v[a]++;
        v[b + 1]--;
    }

    rep(i, 1e7) {
        s[i + 1] = s[i] + v[i];
    }

    cout << *max_element(all(s)) << endl;
}