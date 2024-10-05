#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    int n, m, l;
    cin >> n;
    set<int> a, b, c;
    rep(i, n) {
        int t;
        cin >> t;
        a.insert(t);
    }

    cin >> m;
    rep(i, m) {
        int t;
        cin >> t;
        b.insert(t);
    }

    cin >> l;
    rep(i, l) {
        int t;
        cin >> t;
        c.insert(t);
    }

    int q;
    cin >> q;
    vector<int> v(q);
    rep(i, q) cin >> v[i];

    set<int> answers;

    repc(ai, a) {
        repc(bi, b) {
            repc(ci, c) {
                answers.insert(ai + bi + ci);
            }
        }
    }

    repc(qi, v) {
        if (answers.contains(qi))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}