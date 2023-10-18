/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define read(v)       \
    for (auto &x : v) \
        cin >> x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define printp(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << nline;
#define printm(m)                                  \
    for (auto it = m.begin(); it != m.end(); it++) \
        cout << it->first << " " << it->second << nline;
#define prints(s)                                  \
    for (auto it = s.begin(); it != s.end(); it++) \
        cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
class SegmentTree
{
    vector<ll> tree;
    vector<ll> lazy;
    int n;

public:
    SegmentTree(int n, vector<int> &v)
    {
        this->n = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
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
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    void update(int left, int right, int value)
    {
        Update(left, right, 0, n - 1, 0, value);
    }
    void Update(int left, int right, int start, int end, int node, int value)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node] * (end - start + 1) * 1LL;
            if (start != end)
            {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > right || end < left)
        {
            return;
        }
        if (start >= left && end <= right)
        {
            tree[node] += (end - start + 1) * value * 1LL;
            if (start != end)
            {
                lazy[node * 2 + 1] += value;
                lazy[node * 2 + 2] += value;
            }
            return;
        }

        int mid = (start + end) / 2;
        Update(left, right, start, mid, 2 * node + 1, value);
        Update(left, right, mid + 1, end, 2 * node + 2, value);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    ll query(int left, int right)
    {
        return Query(left, right, 0, n - 1, 0);
    }
    ll Query(int left, int right, int start, int end, int node)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node] * (end - start + 1) * 1LL;
            if (start != end)
            {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > right || end < left)
        {
            return 0;
        }
        if (start >= left && end <= right)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll leftans = Query(left, right, start, mid, 2 * node + 1);
        ll rightans = Query(left, right, mid + 1, end, 2 * node + 2);
        return leftans + rightans;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vi v(n);
    read(v);
    SegmentTree st(n, v);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int left, right, value;
            cin >> left >> right >> value;
            st.update(left - 1, right - 1, value);
        }
        else
        {
            int k;
            cin >> k;
            cout << st.query(k - 1, k - 1) << nline;
        }
    }
}

int main()
{
    godspeed;
    ll t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll count_of_digits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    ll res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
