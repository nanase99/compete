#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
map<int, pair<int, int>> ans;
vector<bool> visited;
Graph G;
int t = 0;

void dfs(int node) {
    if (!visited[node]) {
        visited[node] = true;
        ans[node].first = ++t;
    } else {
        return;
    }
    repc(e, G[node]) {
        if (e == -1 || e == node) break;
        dfs(e);
    }
    ans[node].second = ++t;
}

int main() {
    int n;
    cin >> n;

    G.resize(n);
    visited.resize(n);

    rep(i, n) {
        int u, k;
        cin >> u >> k;
        G[u - 1].resize(k);
        rep(j, k) {
            int in;
            cin >> in;
            G[u - 1][j] = in - 1;
        }
    }

    while (find(all(visited), false) != visited.end()) {
        auto target = find(all(visited), false);
        dfs(target - visited.begin());
    }

    repc(e, ans) {
        printf("%d %d %d\n", e.first + 1, e.second.first, e.second.second);
    }
    return 0;
}