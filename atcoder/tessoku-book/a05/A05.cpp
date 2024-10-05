#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<pair<int, int>> s;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int remain = k - i - j;
            if (remain > 0 && remain <= n) ans++;
        }
    }

    cout << ans << endl;
}