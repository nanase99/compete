#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
ll N, K;
ll ans = LONG_MAX;
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

void dfs(vector<ll>& v) {
    stack<pair<ll, vector<ll>>> st;
    st.push({0, vector<ll>()});
    ll leftMax = 0;

    while (!st.empty()) {
        auto [index, choices] = st.top();
        st.pop();

        if (choices.size() == K) {
            ll maxHeight = v[choices[0]];
            ll initLeftMax =
                *max_element(v.begin(), next(v.begin(), choices[0]));
            ll localAns = 0;
            ll localMax = 0;
            if (maxHeight < initLeftMax) {
                localAns += initLeftMax - maxHeight;
                maxHeight = initLeftMax;
            }

            for (int i = 1; i < choices.size(); i++) {
                ll height = v[choices[i]];
                maxHeight =
                    max(maxHeight,
                        *max_element(v.begin(), next(v.begin(), choices[i])));
                if (height > maxHeight) {
                    maxHeight = height;
                } else {
                    localAns += maxHeight - height + 1;
                    maxHeight++;
                }
            }
            ans = min(ans, localAns);
            continue;
        }
        if (index == N) continue;
        st.push({index + 1, choices});
        st.push({index + 1, vadd(choices, index)});
    }
}

int main() {
    cin >> N >> K;
    vector v = vector<ll>(N, 0);

    repc(e, v) {
        cin >> e;
    }
    dfs(v);
    cout << ans << endl;
}