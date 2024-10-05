#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
map<ll, ll> cache;

ll dfs(ll n) {
    if (cache.count(n)) {
        return cache[n];
    }

    if (n == 1) {
        return 0LL;
    }

    ll lower = n / 2;
    ll upper = (n + 1) / 2;
    ll upAns = dfs(upper);
    ll lowAns = dfs(lower);
    cache[n] = n + upAns + lowAns;
    return n + upAns + lowAns;
}

int main() {
    ll n;
    cin >> n;
    // priority_queue<ll, vector<ll>, greater<ll>> que;
    // que.push(n);

    ll ans = dfs(n);
    cout << ans << endl;
}