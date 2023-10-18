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
#define int long long
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
#include <bits/stdc++.h>
using namespace std;
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
        tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
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
        return max(ans1, ans2);
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
        tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
};
void solve()
{
    int n;
    cin >> n;
    vi h(n);
    read(h);
    vi a(n);
    read(a);
    vi dp(n, 0);
    SegmentTree st(n, dp);
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {h[i], i};
    }
    sort(all(v));
    for (int i = 0; i < n; i++)
    {
        int index = v[i].second;
        int height = v[i].first;
        int ans = st.query(0, index - 1);
        st.update(index, ans + a[index]);
    }
    cout << st.query(0, n - 1) << nline;
}

int32_t main()
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
