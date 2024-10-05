#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
vector<pair<int, int>> directions = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                                     {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

// pairの+演算
template <typename T1, typename T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2>& lhs,
                            const std::pair<T1, T2>& rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}
// pairの-演算
template <typename T1, typename T2>
std::pair<T1, T2> operator-(const std::pair<T1, T2>& lhs,
                            const std::pair<T1, T2>& rhs) {
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

int w, h;

void dfs(pair<int, int> pos, map<pair<int, int>, bool>& m) {
    if (m.at(pos)) return;
    m[pos] = true;
    repc(e, directions) {
        auto nextPos = pos + e;
        auto [nextH, nextW] = nextPos;
        if (nextH < 0 || nextH >= h) continue;
        if (nextW < 0 || nextW >= w) continue;
        if (m.count(nextPos) && !m[nextPos]) dfs(nextPos, m);
    }
}

int main() {
    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vector<int>> v(h, vector<int>(w));

        rep(i, h) rep(j, w) cin >> v[i][j];

        map<pair<int, int>, bool> m;
        rep(i, h) {
            rep(j, w) {
                if (v[i][j] == 1) {
                    m[{i, j}] = false;
                }
            }
        }
        int ans = 0;
        while (1) {
            auto target = find_if(all(m), [](auto& e) { return !e.second; });
            if (target == m.end()) break;
            dfs(target->first, m);
            ans++;
        }
        cout << ans << endl;
    }
}