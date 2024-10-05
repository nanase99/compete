#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    set<int> s;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    if (s.contains(x))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}