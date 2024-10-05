#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int a, b,d;
    cin >> a >> b>> d;
    int current = a;

    while(1){
        cout << current<< " ";
        current += d;
        if(current > b) break;
    }
    return 0;
}