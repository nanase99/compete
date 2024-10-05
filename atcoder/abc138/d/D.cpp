#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
map<int, int> m;
multimap<int, int> mm;

void dfs(int index, int point, int parentIndex) {
    auto [start, end] = mm.equal_range(index);
    for (auto itr = start; itr != end; ++itr) {
        if (parentIndex == itr->second) continue;
        dfs(itr->second, point + m[index], index);
    }
    m[index] += point;
}

int main() {
    int n, q;
    cin >> n >> q;

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        mm.insert({a - 1, b - 1});
        mm.insert({b - 1, a - 1});
    }

    rep(i, q) {
        int x, p;
        cin >> p >> x;
        m[p - 1] += x;
    }
    dfs(0, 0, 0);

    repc(e, m) {
        cout << e.second << " ";
    }
}