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
    vi nums;
    int x;
    while (cin >> x) {
        nums.pb(x);
    }

    // solution format
    int ans = 0;
    int length = 0;

    int n = sz(nums);

    rep(i, 0, n) {
        if (nums[i] == 1) {
            length += 1;
            ans = max(ans, length);
        } else {
            length = 0;
        }
        ans = max(ans, length);
    }

    cout << ans << '\n';
    return 0;
}