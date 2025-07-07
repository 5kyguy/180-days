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
    vector<vector<int>> matrix;
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
        matrix.pb(temp);
    }

    int n = size(matrix);
    int m = size(matrix[0]);
    vector<int> ans(n*m, 0);

    int left = 0, right = m - 1; 
    int top = 0, bottom = n - 1;
    int index = 0;

    int no_of_rounds = (min(n,m) + 1) / 2;

    for (int j = 0; j < no_of_rounds; ++j) {
        // left to right
        if (top <= bottom) {
            for (int i = left; i <= right; ++i)
                ans[index++] = matrix[top][i];
            top++;
        }

        //top to bottom
        if (left <= right) {
            for (int i = top; i <= bottom; ++i)
                ans[index++] = matrix[i][right];
            right--;
        }

        // right to left
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                ans[index++] = matrix[bottom][i];
            bottom--;
        }

        //bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                ans[index++] = matrix[i][left];
            left++;
        }
    }
   
    print_vec(ans);
    return 0;
}