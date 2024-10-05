#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int a,b;
    cin >> a>>b;
    rep(i,10){
        if(i != (a+b)){
            cout << i << endl;
            return 0;
        }
    }
}