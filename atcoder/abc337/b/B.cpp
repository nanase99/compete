#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    string tmp;
    int ind = 0;
    rep(i, s.length()) {
        char ch = s[i];
        if (!(ch == 'A' || ch == ' ')) {
            break;
        }
        ind++;
    }
    s = s.substr(ind);
    ind = 0;
    rep(i, s.length()) {
        char ch = s[i];
        if (!(ch == 'B' || ch == ' ')) {
            break;
        }
        ind++;
    }

    s = s.substr(ind);
    ind = 0;
    rep(i, s.length()) {
        char ch = s[i];
        if (!(ch == 'C' || ch == ' ')) {
            break;
        }
        ind++;
    }
    s = s.substr(ind);

    repc(c, s) {
        if (c == ' ')
            continue;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}