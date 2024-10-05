#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int N, L, R;
    cin >> N >> L >> R;

    vector A = vector<int>(N, 0);
    repc(e, A) {
        cin >> e;
    }

    repc(e, A) {
        int localMin = min(abs(e - L), abs(e - R));
        // if (L <= e && e <= R) localMin = e;
        if (L <= e && e <= R) {
            cout << e << " ";
            continue;
        };

        // for (int i = L; i <= R; i++) {
        // localMin = min(localMin, abs(e - i));
        // }

        // for (int i = L; i <= R; i++) {
        //     if (abs(e - i) <= localMin) {
        //         cout << i << " ";
        //     }
        // }
        if (abs(e - R) <= localMin) {
            cout << R << " ";
        } else {
            cout << L << " ";
        }
    }
}