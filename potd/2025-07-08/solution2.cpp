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

    int last_non_two = 0;
    rep (i, 0, n) {
        if (nums[i] != 2 ) {
            int temp = nums[i];
            nums[i] = nums[last_non_two];
            nums[last_non_two] = temp;
            last_non_two++;
        }
    }
    int last_non_one = 0;
    rep (i, 0, last_non_two) {
        if (nums[i] != 1) {
            int temp = nums[i];
            nums[i] = nums[last_non_one];
            nums[last_non_one] = temp;
            last_non_one++;
        }
    }
    print_vec(nums);
    return 0;
}
