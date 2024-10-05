#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<vector<char>> P(N, vector<char>(N));
    map<int, int> cnt;

    repc(row, P) repc(col, row) {
        char c;
        cin >> c;
        col = c;
    };

    rep(i, N) {
        ll sum = 0;
        rep(j, N) {
            if (P[j][i] == 'B') sum++;
        }
        cnt[i] = sum;
    }

    rep(coutner, Q) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        int top = A % N;
        int under = C % N;
        int left = B % N;
        int right = D % N;
        ll ans = 0;
        for (int i = B; i <= D; i++) {
            ans += cnt[i % N];
        }
        cout << ans << endl;
    }
}