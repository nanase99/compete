#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
vector<ll> copyStorePos, copyDeliverPos;

bool isOK(int index, int key) {
    if (copyStorePos[index] >= key)
        return true;
    else
        return false;
}
int binary_search(int key) {
    int ng = -1;
    int ok = (int)copyStorePos.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    ll d, n, m;
    cin >> d >> n >> m;

    vector<ll> storePos(n), deliverPos(m);
    storePos[0] = 0;
    rep(i, n - 1) cin >> storePos[i + 1];
    rep(i, m) cin >> deliverPos[i];
    sort(all(storePos));
    copyStorePos = storePos;
    copyDeliverPos = deliverPos;

    ll ans = 0;

    repc(deliver, deliverPos) {
        int target = binary_search(deliver);
        if (target >= storePos.size()) {
            ans += min(min(abs(storePos[target - 1] - deliver),
                           abs(storePos[target] - deliver)),
                       abs(d - deliver));
        } else if (target == -1) {
            ans += min(abs(storePos[storePos.size() - 1] - deliver),
                       abs(storePos[0] - deliver));
        } else {
            ll localAns = LONG_MAX;
            localAns = min(abs(storePos[target] - deliver),
                           abs(storePos[target + 1] - deliver));
            if (target != 0) {
                localAns = min(localAns, abs(storePos[target - 1] - deliver));
            }
            ans += localAns;
        }
    }
    cout << ans << endl;
}