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
    int n;
    cin >> n;

    bool ans = true;


    if (n == 1) {
        ans = true;
    } else if (n <= 0) {
        ans = false; 
    } else {
        while (n > 1) {
            if (n % 2 != 0)
                return false;
            n /= 2; // divide by 2
        }
        if (n != 1) {
            ans = false; // if n is not 1, then it is not a power of 2
        }
    }


    if (ans)
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}