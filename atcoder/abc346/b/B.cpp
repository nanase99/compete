#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;
string pattern = "wbwbwwbwbwbw";
int main() {
    int w, b;
    cin >> w >> b;

    string inf;
    rep(i, 30) inf += pattern;

    rep(i, inf.size()) {
        for (int j = 1; j <= inf.size(); j++) {
            map<char, int> m;
            string sb = inf.substr(i, j);
            repc(c, sb) {
                m[c]++;
            }
            if (m['w'] == w && m['b'] == b) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}