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
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {};
    };
    // take input for 2 linked lists
    vector<int> vals1, vals2;
    string line;
    getline(cin, line);
    istringstream iss1(line);
    int x;
    while (iss1 >> x) vals1.pb(x);
    getline(cin, line);
    istringstream iss2(line);
    while (iss2 >> x) vals2.pb(x);

    // Create first linked list
    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;
    for (int v : vals1) {
        if (!list1) {
            list1 = tail1 = new ListNode(v);
        } else {
            tail1->next = new ListNode(v);
            tail1 = tail1->next;
        }
    }

    // Create second linked list
    ListNode* list2 = nullptr;
    ListNode* tail2 = nullptr;
    for (int v : vals2) {
        if (!list2) {
            list2 = tail2 = new ListNode(v);
        } else {
            tail2->next = new ListNode(v);
            tail2 = tail2->next;
        }
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    
    //print the merged linked list
    ListNode* current = dummy.next;
    if (!current) {
        cout << "null" << '\n';
    } else {
        while (current) {
            cout << current->val;
            current = current->next;
            if (current) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}