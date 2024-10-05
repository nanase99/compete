#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int dp[3010][3010];

int main() {
    string s, t;
    cin >> s >> t;
    int ssize = s.size();
    int tsize = t.size();

    rep(i, ssize + 1) {
        rep(j, tsize + 1) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            chmax(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    string ans = "";
    while (ssize > 0 && tsize > 0) {
        if (dp[ssize][tsize] == dp[ssize][tsize - 1])
            tsize--;
        else if (dp[ssize][tsize] == dp[ssize - 1][tsize])
            ssize--;
        else if (dp[ssize][tsize] == dp[ssize - 1][tsize - 1] + 1) {
            ssize--;
            tsize--;
            ans += s[ssize];
            continue;
        }
    }

    rep(i, ans.size()) {
        cout << ans[ans.size() - i - 1];
    }
    cout << endl;
}