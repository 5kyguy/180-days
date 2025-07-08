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

    // flag if the row had zero, if not, we restore the original row
    bool zeroFoundInRow = false;
    // to store the original row
    vector<int> ogRow(m, 0);
    // flags for which col to be 0ed
    vector<bool> cols(m, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // if the col is to be 0ed, if not store the original one
            if (cols[j] == true) {
                ogRow[j] = 0;
            } else {
                ogRow[j] += matrix[i][j];
            }
            if (matrix[i][j] == 0) {
                zeroFoundInRow = true;
                cols[j] = true;

                // set 0 in the col above too
                for (int k = i; k >= 0; --k)
                    matrix[k][j] = 0;
            }
            matrix[i][j] = 0;
        }
        // if no zero in row, restore the original one
        if (zeroFoundInRow == false) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = ogRow[j];
            }
        }
        // reset the row and the flag
        zeroFoundInRow = false;
        fill(ogRow.begin(), ogRow.end(), 0);
    }

    // print the 2D vector
    for (const auto& row : matrix) {
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