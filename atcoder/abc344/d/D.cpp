#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int n;
string t;
int dp[110][110];
int main() {
    int INF = 1001001001;
    cin >> t >> n;
    vector<vector<string>> s(n, vector<string>());
    rep(i, 110) rep(j, 110) dp[i][j] = INF;
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            string si;
            cin >> si;
            s[i].push_back(si);
        }
    }

    dp[0][0] = 0;

    rep(i, n + 1) {
        if (i == 0) continue;
        rep(j, t.size() + 1) {
            chmin(dp[i][j], dp[i - 1][j]);
            cout << s[i - 1].size() << endl;
            repc(str, s[i - 1]) {
                if (j - (int)str.length() < 0) continue;
                bool flg = true;
                rep(k, str.length()) {
                    if (t[j - str.length() + k] != str[k]) flg = false;
                }
                if (flg) chmin(dp[i][j], dp[i - 1][j - (int)str.length()] + 1);
            }
        }
    }
    if (dp[n][t.size()] >= INF)
        cout << "-1" << endl;
    else
        cout << dp[n][t.size()] << endl;
}