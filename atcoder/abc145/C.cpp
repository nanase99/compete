#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    std::cout << std::fixed << std::setprecision(10);
    ll N;
    cin >> N;

    vector xy = vector<pair<ll, ll>>(N);
    repc(e, xy) {
        ll x, y;
        cin >> x >> y;
        e = {x, y};
    }

    double dist = 0.;
    int count = 0;
    sort(all(xy));
    do {
        count++;
        double tmpDist = 0.;
        for (int i = 0; i < xy.size() - 1; i++) {
            auto first = xy[i];
            auto second = xy[i + 1];
            tmpDist += sqrt((first.first - second.first) *
                                (first.first - second.first) +
                            (first.second - second.second) *
                                (first.second - second.second));
        }
        dist += tmpDist;
    } while (next_permutation(all(xy)));
    double ans = dist / count;
    cout << ans << endl;
}