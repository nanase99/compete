#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N + 1), P(N + 1);
    A[0] = -10000;
    P[0] = -10000;
    P[1] = -10000;
    rep(i, N) cin >> A[i + 1];
    rep(i, N - 1) cin >> P[i + 2];

    // for (int j = 2; j < N + 1; j++) {
    //     int index = P[j];
    //     A[index] = A[index] + A[j];
    // }

    vector<int> targetIndex;
    vector<int> searchIndex;
    searchIndex.push_back(1);
    int prevSearchIndexSize = 1;
    do {
        for (int i = 2; i < N + 1; i++) {
            if (P[i] == searchIndex[searchIndex.size() - 1]) {
                searchIndex.push_back(i);
                prevSearchIndexSize++;
            }
        }
    } while (searchIndex.size() != prevSearchIndexSize);

    ll target = A[1];
    repc(index, searchIndex) {
        A[index] = A[index];
    }

    // if (A[1] > 0)
    //     cout << "+" << endl;
    // else if (A[1] < 0)
    //     cout << "-" << endl;
    // else
    //     cout << "0" << endl;

    if (target > 0)
        cout << "+" << endl;
    else if (target < 0)
        cout << "-" << endl;
    else
        cout << "0" << endl;
}