#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    map<char, char> m, m2;
    vector<char> v;
    vector<pair<char, char>> order;
    rep(i, q) {
        char c, d;
        cin >> c >> d;
        v.push_back(c);
        if (m.count(c)) {
            order.push_back(c, m[c]);
        }
        if (m2.count(c)) {
            m[m2[c]] = d;
            m[c] = d;
            m2.erase(c);
        } else {
            m[c] = d;
            m2[d] = c;
        }
    }
    repc(e, v) {
        auto to = m[e];
        replace(all(s), e, to);
    }
    cout << s << endl;
}