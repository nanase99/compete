#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int R, C;
int ans = 0;

/**
 * @brief vectorに要素を追加したvectorを返します
 * @param v 要素を追加するvector
 * @param e 追加する要素
 * @return vにeを追加したvector
 */
template <class T>
std::vector<T> vadd(const std::vector<T> v, T e) {
    std::vector<T> copy = v;
    copy.emplace_back(e);
    return copy;
}

void dfs(vector<vector<int>>& v) {
    stack<pair<int, vector<vector<int>>>> st;
    st.push({0, v});

    while (!st.empty()) {
        auto [index, mat] = st.top();
        st.pop();

        if (index == R) {
            int localAns = 0;
            for (int i = 0; i < C; i++) {
                int colCount = 0;
                for (int j = 0; j < R; j++) {
                    if (mat[j][i] == 0) {
                        colCount++;
                    }
                }
                localAns += max(colCount, R - colCount);
            }
            ans = max(ans, localAns);
            continue;
        }

        st.push({index + 1, mat});
        auto copy = mat;
        repc(e, copy[index]) {
            e = 1 - e;
        }
        st.push({index + 1, copy});
    }
}

int main() {
    cin >> R >> C;
    vector v = vector<vector<int>>(R, vector<int>(C, 0));

    repc(row, v) {
        repc(col, row) {
            cin >> col;
        }
    }

    dfs(v);

    cout << ans << endl;
}