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
    vector<int> v(n);

    rep(i, n) {
        cin >> v[i];
    }

    rep(i, v.size() - 1) {
        cout << v[i] * v[i + 1] << " ";
    }
    cout << endl;
}