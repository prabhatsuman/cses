#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18
#define NINF (ll) - 1e18
struct node
{
    ll u, v, w;
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, -w});
    }
    vector<ll> dist(n + 1, INF);
    // apply belmen ford
    // n-1 times relax and propagete
    // if in nth time also relax then negative cycle is present
    dist[1] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (auto it : edges)
        {
            ll u = it.u;
            ll v = it.v;
            ll w = it.w;
            // cout<<dist[u]<<" "<<dist[v]<<" "<<w<<endl;
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], dist[u] + w);
            // cout<<dist[v]<<endl;
            dist[v] = max(dist[v], NINF);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (auto it : edges)
        {
            int u = it.u;
            int v = it.v;
            int w = it.w;
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + w < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<dist[i]<<" ";
    // }
    // cout<<endl;

    if (dist[n] == NINF)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << -dist[n] << endl;
    }
}