#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> memo, cnt;
    set<ll> index;
    ll sum = 0;

    repc(e, A) {
        ll tmp;
        cin >> tmp;
        e = tmp;
        cnt[tmp]++;
        index.insert(tmp);
    }

    ll now = accumulate(all(A), 0LL);
    repc(e, index) {
        memo[e] = now - e * cnt[e];
        now = now - e * cnt[e];
    }

    repc(e, A) {
        cout << memo[e] << " ";
    }
}