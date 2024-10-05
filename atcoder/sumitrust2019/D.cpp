#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto& e : c)
#define PI 3.14159265359
using namespace std;
typedef long long ll;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;

    for (char i = '0'; i <= '9'; i++) {
        auto firstItr = find(S.begin(), S.end(), i);
        if (firstItr == S.end()) continue;
        for (char j = '0'; j <= '9'; j++) {
            auto secondItr = find(firstItr + 1, S.end(), j);
            if (secondItr == S.end()) continue;
            for (char k = '0'; k <= '9'; k++) {
                auto thirdItr = find(secondItr + 1, S.end(), k);
                if (thirdItr == S.end()) continue;
                ans++;
            }
        }
    }

    cout << ans << endl;
}