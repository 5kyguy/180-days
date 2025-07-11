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
    string haystack, needle;
    cin >> haystack;
    cin >> needle;
    int ans = 0;

    if (size(haystack) < size(needle))
        cout << '-1';
    for (int i = 0; i < size(haystack) - size(needle) + 1; ++i) {
        if (haystack[i] == needle[0]) {
            bool found = true;
            int k = 1;
            for (int j = i + 1; j < i + size(needle); ++j) {
                if (haystack[j] != needle[k]) {
                    found = false;
                    break;
                }
                k++;
            }
            if (found == true) {
                ans = i;
                break;
            } else {
                ans = -1;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}