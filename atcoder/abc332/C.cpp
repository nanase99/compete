#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    int ans = 0;

    rep(i, N + 1) {
        int logo = i;
        int muji = M;
        bool flg = true;
        repc(e, S) {
            if (!flg) break;
            if (e == '0') {
                muji = M;
                logo = i;
            } else if (e == '1') {
                if (muji > 0) {
                    muji--;
                } else {
                    logo--;
                    if (logo < 0) {
                        flg = false;
                    }
                }
            } else {
                logo--;
                if (logo < 0) {
                    flg = false;
                }
            }
        }
        if (flg) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}