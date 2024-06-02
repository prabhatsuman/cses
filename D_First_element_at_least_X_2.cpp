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
class SegmentTree
{
    vector<int> tree;
    int n;

public:
    SegmentTree(int n, vector<int> &v)
    {
        this->n = n;
        tree.resize(4 * n);
        build(v, 0, n - 1, 0);
    }
    void build(vector<int> &v, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(v, start, mid, 2 * node + 1);
        build(v, mid + 1, end, 2 * node + 2);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    int merge(int node1, int node2)
    {
        return max(node1, node2);
    }
    int query(int x, int l)
    {
        return Query(x, 0, n - 1, 0, l);
    }
    int Query(int x, int start, int end, int node, int l)
    {
        if (tree[node] < x)
            return -1;
        if (end < l)
            return -1;
        if (start == end)
        {
            return start;
        }
        int mid = (start + end) / 2;
        // debug(start, end, mid,tree[node]);
        int q1 = Query(x, start, mid, 2 * node + 1, l);
        if (q1 == -1)
        {
            return Query(x, mid + 1, end, 2 * node + 2, l);
        }
        return q1;
    }
    void update(int index, int value)
    {
        Update(index, value, 0, n - 1, 0);
    }
    void Update(int index, int value, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            Update(index, value, start, mid, 2 * node + 1);
        }
        else
        {
            Update(index, value, mid + 1, end, 2 * node + 2);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    read(v);
    SegmentTree st(n, v);
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int k, u;
            cin >> k >> u;
            st.update(k, u);
        }
        else
        {
            int x, l;
            cin >> x >> l;
            cout << st.query(x, l) << nline;
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