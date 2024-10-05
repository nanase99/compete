#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> P, Q;
    P = vector<int>(N, 0);
    Q = vector<int>(N, 0);
    ll pCount = 0, qCount = 0;

    repc(e, P) {
        cin >> e;
    }
    repc(e, Q) {
        cin >> e;
    }

    auto copy = P;

    sort(all(copy));
    bool Pflg = true, Qflg = true;
    do {
        if (copy == P) Pflg = false;
        if (Pflg) pCount++;
        if (copy == Q) Qflg = false;
        if (Qflg) qCount++;
    } while (next_permutation(all(copy)));

    cout << abs(pCount - qCount) << endl;
}