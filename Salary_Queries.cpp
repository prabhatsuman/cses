/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;

typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
#define read(v)       \
    for (auto &x : v) \
        cin >> x;

#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
struct Node
{
    int sum;
    Node *left, *right;
    Node()
    {
        sum = 0;
        left = right = NULL;
    }
    void add(Node *root, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            root->sum += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            if (!root->left)
                root->left = new Node();
                
            add(root->left, l, mid, pos, val);
        }
        else
        {
            if (!root->right)
                root->right = new Node();
            add(root->right, mid + 1, r, pos, val);
        }
        root->sum = 0;
        if (root->left)
            root->sum += root->left->sum;
        if (root->right)
            root->sum += root->right->sum;
    }
    int query(Node *root, int l, int r, int x, int y)
    {
        if (x <= l && r <= y)
            return root->sum;
        if (r < x || y < l)
            return 0;
        int mid = (l + r) / 2;
        int res = 0;
        if (root->left)
            res += query(root->left, l, mid, x, y);
        if (root->right)
            res += query(root->right, mid + 1, r, x, y);
        return res;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    Node *root = new Node();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        root->add(root, 1, 1e9 + 1, a[i], 1);
    }
    while (q--)
    {
        char type;
        cin >> type;
        if (type == '?')
        {
            int l, r;
            cin >> l >> r;
            cout << root->query(root, 1, 1e9 + 1, l, r) << nline;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            root->add(root, 1, 1e9 + 1, a[x - 1], -1);
            a[x - 1] = y;
            root->add(root, 1, 1e9 + 1, a[x - 1], 1);
        }
    }
}

signed main()
{
    godspeed;
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}