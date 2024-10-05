#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
vector<int> ans;
vector<vector<int>> v;
vector<bool> visited;

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [pos, depth] = q.front();
        q.pop();
        if (visited[pos]) continue;
        visited[pos] = true;
        ans[pos] = depth;

        repc(e, v[pos]) {
            q.push({e, depth + 1});
        }
    }
}

int main() {
    int n;
    cin >> n;
    v.resize(n);
    ans.resize(n, -1);
    visited.resize(n, false);

    rep(i, n) {
        int u, k;
        cin >> u >> k;
        rep(j, k) {
            int tmp;
            cin >> tmp;
            v[u - 1].push_back(tmp - 1);
        }
    }
    bfs();

    rep(i, n) cout << i + 1 << " " << ans[i] << endl;
}