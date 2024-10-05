#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

// 整数を逆順の文字列に変換する関数
std::string reverseIntToString(int n) {
    std::string original = std::to_string(n);
    std::string reversed(original.rbegin(), original.rend());
    return reversed;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 1;
    for (ll i = 2; i * i * i <= n; i++) {
        ll num = i * i * i;
        string s = to_string(num);
        if (s == string(s.rbegin(), s.rend())) ans = num;
    }
    cout << ans << endl;
}
