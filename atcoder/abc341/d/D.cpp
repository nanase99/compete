#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll cm = lcm(n, m);
    vector<ll> v;

    ll current = n;
    while (current < cm) {
        v.push_back(current);
        current += n;
    }

    current = m;
    while (current < cm) {
        v.push_back(current);
        current += m;
    }

    sort(all(v));

    auto index = k % v.size();
    auto base = index > 0 ? v[index - 1] : v[0];
    auto times = k / v.size();
    if (index != 0) times += 1;
    cout << base + (cm * (times - 1)) << endl;
}