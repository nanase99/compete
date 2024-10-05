#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v(N), enemy, gettedPotion;
    map<int, map<int, int>> potion;
    map<int, int> tmpPotion;
    vector<int> ans;
    int ansSize = INT_MAX;
    rep(i, N) {
        int f, s;
        cin >> f >> s;
        v[i].first = f;
        v[i].second = s;
        if (f == 1) {
            tmpPotion[i]++;
            gettedPotion.push_back({f, s});
        } else {
            enemy.push_back({i, s});
            potion[i] = tmpPotion;
        }
    }

    repc(e, enemy) {
        int encountTime = e.first;
        int enemyType = e.second;
        auto atPotion = potion[encountTime];
        ansSize = min(ansSize, (int)atPotion.size());
        if (atPotion[enemyType] <= 0) {
            cout << "-1" << endl;
            return 0;
        }
        atPotion[enemyType]--;
    }
    int prevTime = 0;
    repc(timePotion, potion) {
        int i = 0;
        while (i != timePotion.first - prevTime) {
            if (timePotion.second.contains(gettedPotion[i].second)) {
                ans.push_back(0);
            } else {
                ans.push_back(1);
            }
            i++;
            prevTime = timePotion.first;
        }
    }

    cout << ansSize << endl;
    repc(e, ans) {
        cout << e << " ";
    }
}