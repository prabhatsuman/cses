#include <bits/stdc++.h>
using namespace std;
#define M (int)(1e9 + 7)
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<int> dp(n + 1, 0);
    queue<int> q;
    for (int i = 2; i <= n; i++)
    {
        if (!indegree[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            indegree[child]--;
            if (!indegree[child] && child != 1)
            {
                q.push(child);
            }
        }
    }
    q.push(1);
    dp[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            indegree[child]--;
            dp[child] = (dp[child] + dp[node]) % M;
            if (!indegree[child])
            {
                q.push(child);
                // dp[child]=1;
            }
        }
    }
    cout << dp[n];
}