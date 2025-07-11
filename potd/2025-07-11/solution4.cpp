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
    string t;
    cin >> t;

    bool ans;

    unordered_map<char, char> mapping;
    unordered_map<char, char> reverse_mapping;

    if (s.size() != t.size()) {
        ans = false;
    } else {
        ans = true;
        for (int i = 0; i < s.size(); ++i) {
            if (mapping.count(s[i]) && mapping[s[i]] != t[i]) {
                ans = false;
                break;
            }
            if (reverse_mapping.count(t[i]) && reverse_mapping[t[i]] != s[i]) {
                ans = false;
                break;
            }
            mapping[s[i]] = t[i];
            reverse_mapping[t[i]] = s[i];
        }
    }
    cout << ans << '\n';
    return 0;
}