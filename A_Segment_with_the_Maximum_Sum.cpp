/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define M 1000000007
#define nline '\n'
using namespace std;
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
#define read(v)       \
    for (auto &x : v) \
        cin >> x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";           \
    cout << nline;
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
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
    vector<int> tree;
    vector<int> suffix;
    vector<int> prefix;
    vector<int> sum;
    int n;

public:
    SegmentTree(int n, vector<int> &v)
    {
        this->n = n;
        tree.resize(4 * n);
        suffix.resize(4 * n);
        prefix.resize(4 * n);
        sum.resize(4 * n);
        build(v, 0, n - 1, 0);
    }
    void build(vector<int> &v, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = max(v[start], 0LL);
            sum[node] = v[start];
            prefix[node] = max(v[start], 0LL);
            suffix[node] = max(v[start], 0LL);

            return;
        }
        int mid = (start + end) / 2;
        build(v, start, mid, 2 * node + 1);
        build(v, mid + 1, end, 2 * node + 2);
        tree[node] = max({tree[node * 2 + 1], tree[node * 2 + 2], suffix[node * 2 + 1] + prefix[node * 2 + 2]});
        prefix[node] = max(prefix[node * 2 + 1], sum[node * 2 + 1] + prefix[node * 2 + 2]);
        suffix[node] = max(suffix[node * 2 + 2], sum[node * 2 + 2] + suffix[node * 2 + 1]);
        sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
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
        int ans3 = max({ans1, ans2, suffix[2 * node + 1] + prefix[2 * node + 2]});
        return ans3;
    }
    void update(int index, int value)
    {
        Update(index, value, 0, n - 1, 0);
    }
    void Update(int index, int value, int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = max(value, 0LL);
            sum[node] = value;
            prefix[node] = max(value, 0LL);
            suffix[node] = max(value, 0LL);
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
        tree[node] = max({tree[node * 2 + 1], tree[node * 2 + 2], suffix[node * 2 + 1] + prefix[node * 2 + 2]});
        prefix[node] = max(prefix[node * 2 + 1], sum[node * 2 + 1] + prefix[node * 2 + 2]);
        suffix[node] = max(suffix[node * 2 + 2], sum[node * 2 + 2] + suffix[node * 2 + 1]);
        sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    read(v);
    SegmentTree st(n, v);
    cout << st.query(0, n - 1) << endl;
    while (m--)
    {
        int index, value;
        cin >> index >> value;
        st.update(index, value);
        cout << st.query(0, n - 1) << nline;
    }
}

signed main()
{
    godspeed;
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
