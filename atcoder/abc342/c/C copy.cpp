#include <bits/stdc++.h>
#include <boost/algorithm/string/replace.hpp>

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
    rep(i, q) {
        string c, d;
        cin >> c >> d;
        boost::replace_all(s, c, d);
    }
    cout << s << endl;
}