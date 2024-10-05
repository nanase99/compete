#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    set<tuple<pair<ll, ll>, pair<ll, ll>, pair<ll, ll>>> s;

    vector v = vector<vector<char>>(N, vector<char>());
    map<ll, ll> row, col;
    rep(i, N) {
        string tmp;
        cin >> tmp;
        rep(j, N) {
            v[i].push_back(tmp[j]);
            if (tmp[j] == 'o') {
                col[i]++;
                row[j]++;
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int k = 0; k < N; k++) {
    //         if (v[i][k] == 'o') {
    //             for (int j = k + 1; j < N; j++) {
    //                 if (v[i][j] == 'o') {
    //                     for (int l = i + 1; l < N; l++) {
    //                         if (v[l][k] == 'o') {
    //                             ans++;
    //                             s.insert({
    //                                 {i, k},
    //                                 {i, j},
    //                                 {l, k},
    //                             });
    //                         }
    //                         if (v[l][j] == 'o') {
    //                             ans++;
    //                             s.insert({
    //                                 {i, k},
    //                                 {i, j},
    //                                 {l, j},
    //                             });
    //                         }
    //                     }
    //                     // for (int l = i + 1; l < N; l++) {
    //                     // }
    //                 }
    //             }
    //         }
    //     }
    // }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 'o') {
                ans += (col[i] - 1) * (row[j] - 1);
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (v[i][j] == 'o') {
    //             row[i]++;
    //         }
    //     }
    // }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (v[j][i] == 'o') {
    //             col[i]++;
    //         }
    //     }
    // }

    cout << ans << endl;
}