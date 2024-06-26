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
    vector<pair<int, int>> adj[n + 1];
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] & 1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    vector<int> ans;
    vector<bool> vis(m, false);
    function<void(int)> dfs = [&](int node) -> void
    {
        for (auto it : adj[node])
        {
            if (vis[it.second])
            {
                continue;
            }
            vis[it.second] = true;
            dfs(it.first);
        }
        ans.push_back(node);
    };
    dfs(1);
    if(ans.size()!=m+1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for (int it : ans)
    {
        cout << it << " ";
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
