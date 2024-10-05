#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int N, M;

int solve(string s) {
    map<char, int> m;
    repc(c, s) {
        m[c]++;
    }

    int tmp = min(M, m['1']);
    return m['2'] + m['1'] - tmp;
}

int main() {
    string S;
    cin >> N >> M >> S;
    int ans = 0;
    S += "0";
    string now;
    repc(c, S) {
        if (c == '0') {
            ans = max(ans, solve(now));
            now = "";
        } else {
            now += c;
        }
    }

    cout << ans << endl;
}