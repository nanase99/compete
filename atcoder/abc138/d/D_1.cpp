#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
map<int, int> m;
vector<vector<int>> v;

void dfs(int index, int point, int parentIndex) {
    repc(e, v[index]) {
        if (parentIndex == e) continue;
        dfs(e, point + m[index], index);
    }
    m[index] += point;
}

int main() {
    int n, q;
    cin >> n >> q;
    v.resize(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
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