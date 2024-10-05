#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repc(e, c) for (auto&& e : c)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
using boost::algorithm::split;

int main() {
    string s;
    cin >> s;
    std::vector<std::string> buf;
    split(buf, s, boost::is_any_of("."));
    cout << buf[buf.size() - 1] << endl;
}