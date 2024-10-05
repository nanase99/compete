#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int q;
    cin >> q;
    vector<int> s(1e5, 0), ss(1e5, 0);
    vector<bool> prime(1e5, true);

    for (int i = 2; i * i < 1e5; i++) {
        if (prime[i]) {
            for (int j = i + i; j * j < 1e5; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 3; i < 1e5 - 1; i += 2) {
        if (i % 2 == 0) continue;
        if (prime[i] && (prime[(i + 1) / 2])) s[i] = 1;
    }

    for (int i = 1; i < 1e5; i++) {
        ss[i] = ss[i - 1] + s[i];
    }

    for (; q--;) {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << s[l] << endl;
        else
            cout << ss[r] - ss[l - 1] << endl;
    }
}