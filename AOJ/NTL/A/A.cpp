#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> dividers;
    int num = n;
    for (int i = 2; i * i < n; i++) {
        while (num % i == 0) {
            dividers.push_back(i);
            num /= i;
        }
    }
    if (num != 1) dividers.push_back(num);
    sort(all(dividers));
    cout << n << ":";
    repc(n, dividers) {
        cout << " " << n;
    }
    cout << endl;
}