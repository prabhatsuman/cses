#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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
    vector<int> depth(n + 1, 0);
    vector<int> parent(n + 1, 0);
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
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << depth[u] + depth[v] - 2 * depth[lca(u, v)] << endl;
    }
    return 0;
}