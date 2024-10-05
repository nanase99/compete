#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

bool isOk(vector<pair<int, int>> exists, vector<int>& pos) {
    repc(e, exists) {
        if (pos[e.first] != e.second) return false;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (abs(pos[i] - pos[j]) == abs(i - j)) return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<pair<int, int>> exists(k);
    vector<pair<int, int>> queens;

    rep(i, k) cin >> exists[i].first >> exists[i].second;

    vector pos = vector<int>(8);
    iota(all(pos), 0);
    do {
        // pos = {6, 0, 2, 7, 5, 3, 1, 4};
        if (!isOk(exists, pos)) continue;
        // if (!isOk(exists, pos)) cout << "continue" << endl;
        rep(i, pos.size()) {
            queens.push_back({i, pos[i]});
        }
    } while (next_permutation(all(pos)));

    rep(i, 8) {
        rep(j, 8) {
            if (find(all(exists), make_pair(i, j)) != exists.end() ||
                find(all(queens), make_pair(i, j)) != queens.end())
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
}