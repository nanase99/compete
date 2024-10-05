#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), sumTotal(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if ((i - 1) < 0) {
            sumTotal[i] = a[i];
            continue;
        }
        sumTotal[i] = sumTotal[i - 1] + a[i];
    }

    auto min = min_element(all(sumTotal));

    auto defaultNum = max(0LL, -*min);
    // if (min != sumTotal.end() - 1) {
    auto lastNum = sumTotal[sumTotal.size() - 1];
    //     if (lastNum > 0) defaultNum += lastNum;
    //     //     if (lastNum < 0)
    //     //         defaultNum += -lastNum;
    //     //     else
    //     //         defaultNum += lastNum;
    //     // }
    // }
    cout << defaultNum + lastNum << endl;
}