#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int n, q;
vector<int> A, m;

string dfs(int target) {
    stack<pair<int, vector<int>>> st;
    st.push({0, vector<int>()});
    if (accumulate(all(A), 0) < target) {
        return "no";
    }

    while (!st.empty()) {
        auto p = st.top();
        st.pop();
        if (accumulate(all(p.second), 0) == target) {
            return "yes";
        }
        if (accumulate(all(p.second), 0) > target || p.first == A.size()) {
            continue;
        }
        vector<int> copy = p.second;
        copy.push_back(A[p.first]);
        st.push({p.first + 1, copy});
        st.push({p.first + 1, p.second});
    }
    return "no";
}

int main() {
    cin >> n;
    rep(i, n) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    sort(all(A));

    cin >> q;
    rep(i, q) {
        int tmp;
        cin >> tmp;
        m.push_back(tmp);
    }

    repc(e, m) {
        cout << dfs(e) << endl;
    }
    return 0;
}
