#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int N, L;

    cin >> N >> L;
    vector<int> v = vector<int>(N, 0);

    repc(e, v) {
        cin >> e;
    }
    int ans = 0;
    repc(e, v) {
        if (e >= L) ans++;
    }

    cout << ans << endl;
}