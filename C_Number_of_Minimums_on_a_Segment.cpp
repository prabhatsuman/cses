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
    vector<pair<int, int>> tree;
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
            tree[node] = {v[start], 1};
            return;
        }
        int mid = (start + end) / 2;
        build(v, start, mid, 2 * node + 1);
        build(v, mid + 1, end, 2 * node + 2);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    pair<int, int> merge(pair<int, int> node1, pair<int, int> node2)
    {
        if (node1.first > node2.first)
        {
            return node2;
        }
        else if (node1.first < node2.first)
        {
            return node1;
        }
        else
        {
            return {node1.first, node1.second + node2.second};
        }
    }
    pair<int, int> query(int left, int right)
    {
        return Query(left, right, 0, n - 1, 0);
    }
    pair<int, int> Query(int left, int right, int start, int end, int node)
    {
        if (left <= start && right >= end)
        {
            return tree[node];
        }
        if (left > end || right < start)
        {
            return {INT_MAX, 0};
        }
        int mid = (start + end) / 2;
        pair<int, int> ans1 = Query(left, right, start, mid, 2 * node + 1);
        pair<int, int> ans2 = Query(left, right, mid + 1, end, 2 * node + 2);
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
            tree[node] = {value, 1};
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
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int index, value;
            cin >> index >> value;
            st.update(index, value);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            right--;
            
            pair<int, int> ans = st.query(left, right);
            cout << ans.first << " " << ans.second << nline;
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
