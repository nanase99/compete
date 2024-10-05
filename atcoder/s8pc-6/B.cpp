#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
// pairの+演算
template <typename T1, typename T2>
std::pair<T1, T2> operator+(const std::pair<T1, T2>& lhs,
                            const std::pair<T1, T2>& rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}
// pairの-演算
template <typename T1, typename T2>
std::pair<T1, T2> operator-(const std::pair<T1, T2>& lhs,
                            const std::pair<T1, T2>& rhs) {
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> AB;
    vector<ll> A, B;

    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        AB.push_back({a, b});
        A.push_back(a);
        B.push_back(b);
    }

    sort(all(A));
    sort(all(B));

    auto med = make_pair(A[N / 2], B[N / 2]);

    auto ans = accumulate(all(AB), 0LL, [&](auto&& total, auto&& ab) {
        return total + abs(ab.first - med.first) + abs(ab.first - ab.second) +
               abs(ab.second - med.second);
    });

    cout << ans << endl;
}