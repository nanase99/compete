#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    unordered_map<int, int> um;

    rep(i, n) {
        um[v[i]] = i;
    }

    int q;
    cin >> q;
    for (; q--;) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            um[y] = um[x] + 1;
        } else {
            int x;
            cin >> x;
            um[x] = -1;
        }
    }

    map<int, int> m;
    repc(e, um) {
        auto [num, index] = e;
        m[index] = num;
    }

    repc(e, m) {
        auto [index, num] = e;
        cout << num << " ";
    }
}