#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    while (1) {
        int n, x;
        cin >> n >> x;
        if (n == 0 && x == 0) break;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int third = x - i - j;
                if (third > j && third <= n) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}