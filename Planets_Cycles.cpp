#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[i] = a;
        indeg[a]++;
    }
    // 1. topo sort to seperate the cyclic and non cyclic nodes
    vector<int> vis(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        int next = adj[node];
        indeg[next]--;
        if (indeg[next] == 0)
        {
            q.push(next);
            vis[next] = 1;
        }
    }
  
    int c_id = 1;

    // 2. marking each cycle with a unique number
    vector<int> cycle(n + 1, 0);
    vector<int> c_length(n + 1, 0);
    vector<int> cycle_touch(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int len = 0;
        if (vis[i] != 0)
            continue;
        int node = i;

        while (vis[node] != 2)
        {

            vis[node] = 2;
            cycle[node] = c_id;
            cycle_touch[node] = node;
            node = adj[node];
            len++;
        }
        c_length[c_id] = len;
        c_id++;
    }
 

    // 3. identifying the border nodes

    vector<int> depth(n + 1, 0);
    for (int i = topo.size() - 1; i >= 0; i--)
    {
        cycle_touch[topo[i]] = cycle_touch[adj[topo[i]]];
        cycle[topo[i]] = cycle[adj[topo[i]]];
        depth[topo[i]] = depth[adj[topo[i]]] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << c_length[cycle[i]] + depth[i] - depth[cycle_touch[i]] << " ";
    }

    return 0;
}