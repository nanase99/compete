#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
double P;

double ans = pow(10, 18);

double func(double x) {
    return x + P / pow(2, x / 1.5);
}
double funcPrime(double x) {
    return 1. - (pow(2, -x / 1.5) * P * log(2)) / 1.5;
}

double minFunc() {
    // return (3 * log(P * log(2) / 1.5)) / log(4);
    return -1.5 * log(1.5 / (P * log(2))) / log(2);
}

bool isOK(double mid) {
    double prime = funcPrime(mid);
    if (prime > 0) {
        return true;
    } else
        return false;
}

int main() {
    cin >> P;
    std::cout << std::fixed << std::setprecision(10);

    double low = -10;
    double high = 1e18;
    rep(i, 200) {
        double c1 = low + (high - low) / 3.;
        double c2 = low + 2 * (high - low) / 3.;
        if (func(c1) > func(c2))
            low = c1;
        else
            high = c2;
    }

    ans = low < 0 ? P : func(low);
    cout << ans << endl;
}