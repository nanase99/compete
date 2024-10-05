#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    vector<int> v;
    while (1) {
        int a;
        cin >> a;
        v.push_back(a);
        if (a == 0) break;
    };
    reverse(all(v));
    repc(n, v) cout << n << endl;
}