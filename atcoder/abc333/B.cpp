#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    char S1, S2, T1, T2;
    vector<char> v1, v2;

    cin >> S1 >> S2 >> T1 >> T2;

    v1.push_back(S1);
    v1.push_back(S2);
    v2.push_back(T1);
    v2.push_back(T2);
    sort(all(v1));
    sort(all(v2));
    map<pair<char, char>, int> p;
    p[{'A', 'B'}] = 1;
    p[{'A', 'C'}] = 2;
    p[{'A', 'D'}] = 2;
    p[{'A', 'E'}] = 1;

    p[{'B', 'C'}] = 1;
    p[{'B', 'D'}] = 2;
    p[{'B', 'E'}] = 2;

    p[{'C', 'D'}] = 1;
    p[{'C', 'E'}] = 2;

    p[{'D', 'E'}] = 1;

    if (p[{v1[0], v1[1]}] == p[{v2[0], v2[1]}]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}