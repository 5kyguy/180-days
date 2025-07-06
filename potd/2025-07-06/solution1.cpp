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
    vector<vector<int>> nums;
    // input 2D vector of the format 1,2,3 4,5,6 7,8,9
    string line;
    getline(cin, line);
    stringstream rowss(line);
    string row;
    while (rowss >> row) {
        vector<int> temp;
        stringstream ss(row);
        string token;
        while (getline(ss, token, ',')) {
            temp.pb(stoi(token));
        }
        nums.pb(temp);
    }

    // rotate the 2D vector by 90 degrees clockwise in place, without using extra space
    int n = nums.size();
    if (n == 0) return 0; // handle empty input
    int m = nums[0].size();
    // transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < m; ++j) {
            swap(nums[i][j], nums[j][i]);
        }
    }
    // reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(nums[i].begin(), nums[i].end());
    }

    // print the 2D vector
    for (const auto& row : nums) {
        for (const auto& val : row) {
            cout << val;
            if (&val != &row.back()) {
                cout << ',';
            }
        }
        cout << ' ';
    }
    return 0;
}