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
    set<int> p, q;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        p.insert(tmp);
    }
    rep(i, n) {
        int tmp;
        cin >> tmp;
        q.insert(tmp);
    }

    repc(num, p) {
        int remain = k - num;
        if (q.contains(remain)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}