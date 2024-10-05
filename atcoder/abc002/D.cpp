#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
// vectorのadd関数(addした新しいvectorを返す)
template <class T>
std::vector<T> vadd(const std::vector<T> v, T add) {
    std::vector<T> copy = v;
    copy.emplace_back(add);
    return copy;
}

vector<pair<int, int>> rel;
int ans = 0;
int N, M;

void dfs() {
    stack<pair<int, vector<int>>> st;
    st.push({0, {}});

    while (!st.empty()) {
        auto [index, group] = st.top();
        st.pop();

        if (index == N) {
            bool flg = true;
            sort(all(group));
            for (auto itr1 = group.begin(); itr1 != group.end(); ++itr1) {
                for (auto itr2 = next(itr1); itr2 != group.end(); ++itr2) {
                    if (find(all(rel), make_pair(*itr1, *itr2)) == rel.end()) {
                        flg = false;
                        break;
                    }
                }
            }
            if (flg) {
                ans = max(ans, (int)group.size());
            }
            continue;
        }

        st.push({index + 1, vadd(group, index + 1)});
        st.push({index + 1, group});
    }
}

int main() {
    cin >> N >> M;

    rep(i, M) {
        int x, y;
        cin >> x >> y;
        rel.push_back({min(x, y), max(x, y)});
    }

    dfs();
    cout << ans << endl;
}