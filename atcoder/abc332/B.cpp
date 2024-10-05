#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int K, G, M;
    cin >> K >> G >> M;
    int g = 0, m = 0;

    rep(i, K) {
        if (g == G) {
            g = 0;
        } else if (m == 0) {
            m = M;
        } else {
            int remain = G - g;
            if (m > remain) {
                g += remain;
                m -= remain;
            } else {
                g += m;
                m = 0;
            }
        }
    }
    cout << g << " " << m << endl;
}