#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;

    rep(i, n) {
        int tmp;
        cin >> tmp;
        m[tmp] = i;
    }
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        if (m[a] > m[b]) {
            cout << b << "\n";
        } else {
            cout << a << "\n";
        }
    }
}