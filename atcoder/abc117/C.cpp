#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
#define ALL(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    vector<int> v = {1, 2, 3, 4};
    int res = accumulate(v.begin(), v.end(), 0,
                         [](auto& a, auto& b) { return a + b; });

    cout << res;
    return 0;

    // int N, M;
    // cin >> N >> M;
    // vector<int> X;
    // int ans = INT_MAX;
    // rep(i, M) {
    //     int xi;
    //     cin >> xi;
    //     X.push_back(xi);
    // }

    // if (M <= N) {
    //     cout << 0 << endl;
    //     return 0;
    // }

    // sort(X.begin(), X.end());
    // vector<int> diff;
    // vector<int> count;
    // for (int i = 0; i < M - 1; i++) {
    //     diff.push_back(X[i + 1] - X[i]);
    // }

    // sort(ALL(diff), greater<int>());
    // vector<int> targetDiff;
    // copy(diff.begin() + N - 1, diff.end(), back_inserter(targetDiff));

    // ans = accumulate(ALL(targetDiff), 0);

    // cout << ans << endl;
}