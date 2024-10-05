#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    ll ans = 0;

    vector<vector<ll>> A;
    rep(i, N) {
        vector<ll> tmpV;
        rep(j, M) {
            ll tmp;
            cin >> tmp;
            tmpV.push_back(tmp);
        }
        A.push_back(tmpV);
    }

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            ll candidate = 0;
            for (int k = 0; k < N; k++) {
                candidate += max(A[k][i], A[k][j]);
            }
            ans = max(ans, candidate);
        }
    }
    cout << ans << endl;
}