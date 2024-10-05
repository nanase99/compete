#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> m;
    rep(i, n) {
        int in;
        cin >> in;
        m[in] = i + 1;
    }

    int index = -1;
    rep(i, n) {
        cout << m[index] << " ";
        index = m[index];
    }
}