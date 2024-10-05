#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    char top = s[0];

    if (s[1] == s[2] && s[0] != s[1]) {
        cout << 1 << endl;
        return 0;
    }
    rep(i, s.size()) {
        if (top != s[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}