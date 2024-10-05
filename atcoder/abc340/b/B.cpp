#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    vector<ll> a;
    int q; 
    cin>>q;

    rep(i, q){
        int type, arg;
        cin >> type >> arg;
        if(type == 1){
            a.push_back(arg);
        }
        else {
            cout << a[a.size() - arg] << endl;
        }
    }
}