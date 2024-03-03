#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define int long long

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> dist(n + 1, vector<int>(k, INF));

    pq.push({0, 1});
    dist[1][0] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (dist[node][k - 1] < d)
        {
            continue;
        }
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            if (dist[v][k - 1] > d + wt)
            {
                dist[v][k - 1] = d + wt;
                pq.push({dist[v][k - 1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }

    for (auto it : dist[n])
    {
        cout << it << " ";
    }
}