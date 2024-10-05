#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> N(n - 1), M(m), T(n);

    rep(i, n - 1) cin >> N[i];
    rep(i, n - 1) T[i + 1] = T[i] + N[i];
    rep(i, m) cin >> M[i];

    ll current = 0;
    ll sum = 0;
    ll mod = 100000;
    rep(i, m) {
        ll next = current + M[i];
        sum += abs(T[current] - T[next]);
        sum %= mod;
        current = next;
    }

    cout << sum << endl;
}