#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    pair<int, int> x12 = {x2 - x1, y2 - y1};

    pair<int, int> p3 = {x2 + (-x12.second), y2 + x12.first};
    pair<int, int> p4 = {x1 + (-x12.second), y1 + x12.first};

    printf("%d %d %d %d\n", p3.first, p3.second, p4.first, p4.second);
}