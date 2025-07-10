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

    int n = sz(nums);
    if (n == 0) {
        cout << 0 << ", nums = []\n";
        return 0;
    }

    int k = 1;
    rep(i, 1, n) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            ++k;
        }
    }

    cout << k << ", nums = [";
    for (int i = 0; i < n; ++i) {
        if ( i < k ) 
            cout << nums[i];
        else
            cout << ",_";
        if (i < k - 1) cout << ",";
    }
    cout << "]\n";
    return 0;
}