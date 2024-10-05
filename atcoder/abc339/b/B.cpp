#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>> v(h, vector<char>(w, '.'));
    pair<int, int> pos = {0, 0};
    int direction = 0;
    rep(i, n) {
        auto [y, x] = pos;
        if (v[y][x] == '.') {
            v[y][x] = '#';
            direction = (direction + 1) % 4;
            if (direction == 0)
                pos.first = (y - 1) < 0 ? h - 1 : y - 1;
            else if (direction == 1)
                pos.second = (x + 1) % w;
            else if (direction == 2)
                pos.first = (y + 1) % h;
            else if (direction == 3)
                pos.second = (x - 1) < 0 ? w - 1 : x - 1;
        } else {
            v[y][x] = '.';
            direction = (direction - 1) < 0 ? 3 : direction - 1;
            if (direction == 0)
                pos.first = (y - 1) < 0 ? h - 1 : y - 1;
            else if (direction == 1)
                pos.second = (x + 1) % w;
            else if (direction == 2)
                pos.first = (y + 1) % h;
            else if (direction == 3)
                pos.second = (x - 1) < 0 ? w - 1 : x - 1;
        }
    }
    repc(row, v) {
        repc(cell, row) {
            cout << cell;
        }
        cout << endl;
    };
}