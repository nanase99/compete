#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;

    while (x > 0 || y > 0) {
        if (x > 0 && y > 0) {
            if (a + b > 2 * c) {
                int cCount = 2 * min(x, y);
                ans += c * cCount;
                x -= cCount / 2;
                y -= cCount / 2;
                continue;
            }
            if (x > y) {
                ans += y * b;
                y = 0;
                continue;
            } else {
                ans += x * a;
                x = 0;
                continue;
            }
        } else {
            if (x > 0) {
                if (a > 2 * c) {
                    ans += c * 2 * x;
                    x = 0;
                    continue;
                } else {
                    ans += x * a;
                    x = 0;
                    continue;
                }
            } else {
                if (b > 2 * c) {
                    ans += c * 2 * y;
                    y = 0;
                    continue;
                } else {
                    ans += y * b;
                    y = 0;
                    continue;
                }
            }
        }
    }

    cout << ans << endl;
}