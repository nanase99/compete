#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

vector<int> copyS, copyT;

bool isOK(int index, int key) {
    if (copyS[index] >= key)
        return true;
    else
        return false;
}
int binary_search(int key) {
    int ng = -1;
    int ok = (int)copyS.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok >= (int)copyS.size() ? -1 : ok;
}

int main() {
    int n, q;
    cin >> n;
    vector<int> S(n);
    rep(i, n) cin >> S[i];
    cin >> q;
    vector<int> T(q);
    rep(i, q) cin >> T[i];
    copyS = S;
    copyT = T;
    ll ans = 0;
    rep(i, q) {
        int index = binary_search(T[i]);
        if (index != -1 && S[index] == T[i]) ans++;
    }
    cout << ans << endl;
}