#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    map<int, int> cm, rm;

    rep(i, m) {
        int t;
        cin >> t;
        int a, x;
        cin >> a >> x;
        if (t == 1) {
            rm[a] = x;
        } else {
            cm[a] = x;
        }
    }
}