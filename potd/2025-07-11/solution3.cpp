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
    vi nums1, nums2;
    int m, n;
    int x;
    while (cin >> x) {
        nums1.pb(x);
        if (cin.peek() == '\n') break;
    }
    cin >> m;
    while (cin >> x) {
        nums2.pb(x);
        if (cin.peek() == '\n') break;
    }
    cin >> n;

    int a = m - 1;
    int b = n - 1;

    // Merge nums2 into nums1, assuming nums1 has size m + n
    int i = m + n - 1;
    a = m - 1;
    b = n - 1;
    while (a >= 0 && b >= 0) {
        if (nums1[a] > nums2[b]) {
            nums1[i--] = nums1[a--];
        } else {
            nums1[i--] = nums2[b--];
        }
    }
    while (b >= 0) {
        nums1[i--] = nums2[b--];
    }

    print_vec(nums1);
    return 0;
}