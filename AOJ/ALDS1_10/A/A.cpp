#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int fib[50];

int main() {
    int n;
    cin >> n;
    fib[0] = fib[1] = 1;

    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    cout << fib[n] << endl;
}