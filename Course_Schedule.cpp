#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> noIndgree;
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
        {
            noIndgree.push(i);
        }
    }
    vector<int> ans;
    while (!noIndgree.empty())
    {
        int node = noIndgree.front();
        noIndgree.pop();
        ans.push_back(node);
        for (auto child : adj[node])
        {
            indegree[child]--;
            if (!indegree[child])
            {
                noIndgree.push(child);
            }
        }
    }
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }
    return 0;
}