#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;
    int addM = 0, addY = 0;
    int ansY, ansM, ansD;
    if (D == d) {
        addM = 1;
        ansD = 1;
    } else {
        ansD = d + 1;
    }
    if (m + addM > M) {
        addY = 1;
        ansM = 1;
    } else {
        ansM = m + addM;
    }

    cout << y + addY << " " << ansM << " " << ansD;
}