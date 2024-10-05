#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int m, n;

int y[] = {1, 0, -1, 0};
int x[] = {0, 1, 0, -1};
int ans = 0;
void dfs(pair<int, int> pos, map<pair<int, int>, bool>& visited,
         int count = 0) {
    count++;
    visited[pos] = true;
    rep(i, 4) {
        auto nextY = pos.first + y[i];
        auto nextX = pos.second + x[i];
        if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m &&
            visited.count({nextY, nextX}) && !visited[{nextY, nextX}]) {
            dfs({nextY, nextX}, visited, count);
        }
    }
    visited[pos] = false;
    ans = max(count, ans);
}

int main() {
    cin >> m >> n;

    map<pair<int, int>, bool> mp;

    rep(i, n) rep(j, m) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) mp[{i, j}] = false;
    }

    repc(e, mp) {
        map<pair<int, int>, bool> visited = mp;
        dfs(e.first, visited);
    }

    cout << ans << endl;
}