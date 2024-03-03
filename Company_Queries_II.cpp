#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> adj[n + 1];
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    vector<int> depth(n + 1, 0);
    vector<int> parent(n + 1, 0);
    function<void(int, int, int)> dfs = [&](int u, int p, int d)
    {
        depth[u] = d;
        parent[u] = p;
        for (auto v : adj[u])
        {
            if (v != p)
            {
                dfs(v, u, d + 1);
            }
        }
    };
    dfs(1, 0, 0);
    vector<vector<int>> dp(n + 1, vector<int>(30));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = parent[i];
    }
    for (int bit = 1; bit <= 29; bit++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][bit] = dp[dp[i][bit - 1]][bit - 1];
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (depth[a] < depth[b])
        {
            swap(a, b);
        }
        int diff = depth[a] - depth[b];
        for (int bit = 0; bit <= 29; bit++)
        {
            if (diff & (1 << bit))
            {
                a = dp[a][bit];
            }
        }
        if (a == b)
        {
            cout << a << endl;
            continue;
        }
        for (int bit = 29; bit >= 0; bit--)
        {
            if (dp[a][bit] != dp[b][bit])
            {
                a = dp[a][bit];
                b = dp[b][bit];
            }
        }
        cout << parent[a] << endl;
    }
}