#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int N, M;
map<int, vector<int>> s;
vector<int> p;
int ans = 0;

// vectorのadd関数(addした新しいvectorを返す)
template <class T>
std::vector<T> addReturn(const std::vector<T> v, T add) {
    std::vector<T> copy = v;
    copy.emplace_back(add);
    return copy;
}

void dfs() {
    stack<pair<int, vector<int>>> st;
    st.push({0, vector<int>()});

    while (!st.empty()) {
        auto [index, switches] = st.top();
        st.pop();

        bool flg = true;
        if (index == N) {
            repc(e1, s) {
                int sum = 0;
                repc(e2, e1.second) {
                    sum += switches[e2 - 1];
                }
                if (sum % 2 != p[e1.first]) {
                    flg = false;
                }
            }
            if (flg) ans++;
            continue;
        }

        st.push({index + 1, addReturn(switches, 0)});
        st.push({index + 1, addReturn(switches, 1)});
    }
}

int main() {
    cin >> N >> M;

    rep(i, M) {
        int k;
        cin >> k;
        s[i] = vector<int>();
        rep(j, k) {
            int si;
            cin >> si;
            s[i].push_back(si);
        }
    }
    rep(i, M) {
        int pi;
        cin >> pi;
        p.push_back(pi);
    }

    dfs();

    cout << ans << endl;
}