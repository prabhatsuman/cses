#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
        // cout<<"Hi"<<endl;
    }
    vector<int> next(n + 1, -1);
    vector<bool> vis(n + 1, false);
    vector<int> dp(n + 1, -1);
    dp[n] = 1;
    function<void(int, int)> dfs = [&](int node, int par)
    {
        vis[node] = true;

        for (auto it : adj[node])
        {
            // cout<<it<<endl;
            if (vis[it])
                continue;
            dfs(it, node);

            if (dp[it] != -1 && dp[it] + 1 > dp[node])
            {
                dp[node] = dp[it] + 1;
                next[node] = it;
            }
        }
    };
    dfs(1, 0);

    if (dp[1] == -1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << dp[1] << endl;

    int node = 1;
    vector<int> ans;
    ans.push_back(node);
    while (next[node] != -1)
    {
        node = next[node];
        ans.push_back(node);
        // cout<<node<<endl;
    }

    // ans.push_back(1);
    // reverse(ans.begin(), ans.end());
    // cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << " ";
    return 0;
}