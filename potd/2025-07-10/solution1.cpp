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
    string s;
    cin >> s;
    int n = sz(s);
    int ans = 0;

    unordered_map<char, int> val = {
        {'I', 1},   {'V', 5},   {'X', 10},
        {'L', 50},  {'C', 100}, {'D', 500},
        {'M', 1000}
    };

    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && val[s[i]] < val[s[i + 1]]) {
            ans += val[s[i + 1]] - val[s[i]];
            ++i;
        } else {
            ans += val[s[i]];
        }
    }

    cout << ans << '\n';
    return 0;
}