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
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    function<void(int, int, int)> dfs = [&](int node, int par, int d)
    {
        depth[node] = d;
        parent[node] = par;
        for (auto &it : adj[node])
        {
            if (it != par)
            {
                dfs(it, node, d + 1);
            }
        }
    };
    dfs(1, 0, 0);

    vector<vector<int>> up(n + 1, vector<int>(20, 0));
    for (int i = 1; i <= n; i++)
    {
        up[i][0] = parent[i];
    }
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    function<int(int, int)> lca = [&](int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < 20; i++)
        {
            if ((diff >> i) & 1)
            {
                u = up[u][i];
            }
        }
        if (u == v)
            return u;
        for (int i = 19; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    };
    vector<int> prefix(n + 1, 0);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int lca_node = lca(u, v);
        prefix[u]++;
        prefix[v]++;
        prefix[lca_node]--;
        prefix[parent[lca_node]]--;
    }
    function<void(int, int)> dfs2 = [&](int node, int par)
    {
        for (auto &it : adj[node])
        {
            if (it != par)
            {
                dfs2(it, node);
                prefix[node] += prefix[it];
            }
        }
    };
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << prefix[i] << " ";
    }
    cout << endl;
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