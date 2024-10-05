#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    string ans;
    bool flg = true;
    repc(c, s) {
        if (flg) {
            if (c == '|') {
                flg = false;
                continue;
            }
            ans += c;
        } else {
            if (c == '|') {
                flg = true;
                continue;
            }
        }
    }
    cout << ans << endl;
}