#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int H, W;
vector<vector<ll>> A, B;

int dfsW(vector<vector<ll>> v) {
    stack<pair<pair<ll, ll>, vector<vector<ll>>>> st;
    st.push({{0, 0}, v});
    ll ans = LONG_LONG_MAX;
    bool flg = false;
    while (!st.empty()) {
        auto [header, mat] = st.top();
        auto [index, num] = header;
        st.pop();

        if (index == W - 1) {
            if (equal(mat.cbegin(), mat.cend(), B.begin())) {
                flg = true;
                ans = min(ans, num);
            };
            continue;
        }

        st.push({{index + 1, num}, mat});
        // cout << index << endl;
        auto copy = mat;
        rep(i, H) {
            int swap = copy[i][index];
            copy[i][index] = copy[i][index + 1];
            copy[i][index + 1] = swap;
        }
        st.push({{index + 1, num + 1}, copy});
    }
    return flg ? ans : -1;
}

int dfsH() {
    stack<pair<pair<ll, ll>, vector<vector<ll>>>> st;
    st.push({{0L, 0L}, A});
    ll ans = LONG_LONG_MAX;
    bool flg = false;

    while (!st.empty()) {
        auto [header, mat] = st.top();
        auto [index, num] = header;
        st.pop();

        if (index == H - 1) {
            int wans = dfsW(mat);
            if (wans == -1) {
                continue;
            } else {
                flg = true;
                ans = min(wans + num, ans);
            }
            continue;
        }

        st.push({{index + 1, num}, mat});
        auto copy = mat;
        auto swap = copy[index];
        copy[index] = copy[index + 1];
        copy[index + 1] = swap;
        st.push({{index + 1, num + 1}, copy});
    }
    return flg ? ans : -1;
}

int main() {
    cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W, 0)), b(H, vector<ll>(W, 0));

    rep(i, H) rep(j, W) cin >> a[i][j];
    rep(i, H) rep(j, W) cin >> b[i][j];

    A = a;
    B = b;

    ll ans = dfsH();
    cout << ans << endl;
}