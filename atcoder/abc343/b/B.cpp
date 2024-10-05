#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    multimap<int, int> m;
    rep(i, n) rep(j, n) {
        int a;
        cin >> a;
        if (a == 1) m.emplace(i, j + 1);
    }

    rep(i, n) {
        auto itrs = m.equal_range(i);
        for (auto itr = itrs.first; itr != itrs.second; itr++) {
            cout << itr->second << " ";
        }
        cout << endl;
    }
}