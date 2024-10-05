#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    set<int> s;
    for (int i = 1; i <= 100; i++) {
        if (100 % i == 0) {
            s.insert(i);
        }
    }

    for (int i = a; i <= b; i++) {
        if (s.contains(i)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}