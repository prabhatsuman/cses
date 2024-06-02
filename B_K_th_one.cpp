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
        return node1 + node2;
    }
    int query(int left, int right)
    {
        return Query(left, right, 0, n - 1, 0);
    }
    int Query(int left, int right, int start, int end, int node)
    {
        if (left <= start && right >= end)
        {
            return tree[node];
        }
        if (left > end || right < start)
        {
            return 0;
        }
        int mid = (start + end) / 2;
        int ans1 = Query(left, right, start, mid, 2 * node + 1);
        int ans2 = Query(left, right, mid + 1, end, 2 * node + 2);
        return merge(ans1, ans2);
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
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    read(v);
    SegmentTree st(n, v);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index;
            cin >> index;
            v[index] = 1 - v[index];
            st.update(index, v[index]);
        }
        else
        {
            int k;
            cin >> k;
            int left = 0, right = n - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                // debug(mid,st.query(0,mid));
                if (st.query(0, mid) >= k + 1)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            cout << left << nline;
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