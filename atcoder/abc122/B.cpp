#include <bits/stdc++.h>
#include <boost/algorithm/string/replace.hpp>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    int ans = 0;

    for (int i = 0; i < S.length(); i++) {
        for (int j = 0; j < S.length() - i + 1; j++) {
            string sub = S.substr(i, j);
            int len = sub.length();
            boost::replace_all(sub, "A", "");
            boost::replace_all(sub, "C", "");
            boost::replace_all(sub, "G", "");
            boost::replace_all(sub, "T", "");
            if (sub == "") {
                ans = max(ans, len);
            }
        }
    }

    cout << ans << endl;
}