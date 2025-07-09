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

    // pop the last element as the target
    int target = nums.back();
    nums.pop_back();
    int n = sz(nums);

    int ans = 0;

    // map to store the frequency of each sum encountered so far
    unordered_map<int, int> sum_count;
    int sum = 0;
    sum_count[0] = 1;

    rep (i, 0, n) {
        sum += nums[i]; // sum at index i
        
        // if there is a total such that (sum - target) exists, we add the number of such subarrays.
        if (sum_count.count(sum - target))
            ans += sum_count[sum - target];

        // number of times we have encountered this sum value in array increments 
        sum_count[sum]++;
    }

    cout << ans << '\n';
    return 0;
}