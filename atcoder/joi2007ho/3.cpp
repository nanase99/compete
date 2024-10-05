#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> c;
    ll area = 0;

    rep(i, n) {
        int x, y;
        cin >> x >> y;
        c.insert({x, y});
    }

    for (auto itr1 = c.begin(); itr1 != c.end(); ++itr1) {
        for (auto itr2 = next(itr1); itr2 != c.end(); ++itr2) {
            pair<int, int> d = {itr2->first - itr1->first,
                                itr2->second - itr1->second};

            pair<int, int> rotAmountCounterClock = {-d.second, d.first};
            pair<int, int> rotAmountClock = {d.second, -d.first};

            pair<int, int> firstCounterPoint = {
                itr1->first + rotAmountCounterClock.first,
                itr1->second + rotAmountCounterClock.second};
            pair<int, int> secondCounterPoint = {
                itr2->first + rotAmountCounterClock.first,
                itr2->second + rotAmountCounterClock.second};
            pair<int, int> firstClockPoint = {
                itr1->first + rotAmountClock.first,
                itr1->second + rotAmountClock.second};
            pair<int, int> secondClockPoint = {
                itr2->first + rotAmountClock.first,
                itr2->second + rotAmountClock.second};

            if ((c.find(firstCounterPoint) != c.end() &&
                 c.find(secondCounterPoint) != c.end()) ||
                (c.find(firstClockPoint) != c.end() &&
                 c.find(secondClockPoint) != c.end())) {
                area = max(area, ll(d.first * d.first + d.second * d.second));
            }
        }
    }

    cout << area << endl;
}