#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    ll sumX = accumulate(all(x), 0L);
    ll sumY = accumulate(all(y), 0L);

    if (sumX > sumY)
        cout << "Takahashi" << endl;
    else if (sumX < sumY)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;
}