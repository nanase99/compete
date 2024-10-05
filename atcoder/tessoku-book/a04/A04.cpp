#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans;
    while (n > 1) {
        int res = n % 2;
        ans += to_string(res);
        n /= 2;
    }
    ans += to_string(n);
    rep(i, 10 - ans.size()) cout << 0;
    rep(i, ans.size()) cout << ans[ans.size() - i - 1];
    cout << endl;
}