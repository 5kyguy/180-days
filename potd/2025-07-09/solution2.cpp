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
    vi ans(n, 0);

    int pos_index = 0;
    int neg_index = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[pos_index] = nums[i];
            pos_index += 2;
        } else {
            ans[neg_index] = nums[i];
            neg_index += 2;
        }
    }
    
    print_vec(ans);
    return 0;
}
