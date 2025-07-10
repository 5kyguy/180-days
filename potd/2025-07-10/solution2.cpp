#include <bits/stdc++.h>
using namespace std;

// Type aliases
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

// Macros
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

// Constants
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// Utility functions
template<typename T>
void print_vec(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    fast_io;
    vector<string> strs;
    string s;
    while (cin >> s) {
        strs.pb(s);
    }

    if (strs.empty()) {
        cout << "" << '\n';
        return 0;
    }
    string prefix = strs[0];
    for (int i = 1; i < sz(strs); ++i) {
        int j = 0;
        while (j < sz(prefix) && j < sz(strs[i]) && prefix[j] == strs[i][j]) {
            ++j;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) break;
    }
    cout << prefix << '\n';
    return 0;
}