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
    vector<vector<int>> cnt(N, vector<int>(N));

    repc(row, P) repc(col, row) {
        char c;
        cin >> c;
        col = c;
    };

    rep(i, N) {
        rep(j, N) {
            if (P[j][i] == 'B') cnt[i][j] = 1;
        }
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
            for (int j = A; j <= C; j++) {
                ans += cnt[i % N][j % N];
            }
        }
        cout << ans << endl;
    }
}