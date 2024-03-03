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
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].pb(u);
    }
    vector<int> vis(n + 1);
    vector<int> parent(n + 1);

    function<void(int, int)> dfs = [&](int node, int par)
    {
        vis[node] = 1;
        parent[node] = par;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, node);
            }
            else if (vis[it] == 1 && it != par)
            {
                vector<int> ans;
                ans.pb(it);
                int x = node;
                while (x != it)
                {
                    ans.pb(x);
                    x = parent[x];
                }
                ans.pb(it);
                reverse(all(ans));
                cout << ans.size() << nline;
                for (auto it : ans)
                    cout << it << " ";
                exit(0);
            }
        }
      
    };
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, -1);
    }
    cout << "IMPOSSIBLE" << nline;
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
