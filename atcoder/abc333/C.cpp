#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int n;

// ll dfs() {
//     stack<pair<int, vector<string>>> st;
//     set<ll> anss;
//     st.push({0, {"1", "1", "1"}});
//     ll ans = LONG_MAX;
//     while (!st.empty()) {
//         auto [index, v] = st.top();
//         st.pop();
//         if (index == n) {
//             continue;
//         }

//         ans = stoll(v[0]) + stoll(v[1]) + stoll(v[2]);
//         anss.insert(ans);
//         auto copy = v;
//         st.push({index + 1, {v[0] + "1", v[1], v[2]}});
//         st.push({index + 1, {v[0], v[1] + "1", v[2]}});
//         st.push({index + 1, {v[0], v[1], v[2] + "1"}});
//     }
//     return *next(anss.begin(), n - 1);
// }

int main() {
    cin >> n;

    string s1 = "1";
    string s2 = "1";
    string s3 = "1";
    ll ans = -1;

    rep(i, INT_MAX) {
        if (i == n) {
            cout << ans << endl;
            return 0;
            break;
        }

        ans = stoll(s1) + stoll(s2) + stoll(s3);
        if (stoll(s1) == stoll(s3)) {
            s1 += "1";
            s2 = "1";
            s3 = "1";
        } else if (stoll(s2) == stoll(s3)) {
            s2 += "1";
            s3 = "1";
        } else {
            s3 += "1";
        }
    }
}