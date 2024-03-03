
/*
    steps to do in this problem:
    1. since outdegree of each node is 1, we can say that there must be cycles in the graph
    2. we have to identify the cycle in which the node lies and the lengths of the cycles
    3. mark each cycle with a unique number
    4. find the length of the cycles
    5. find the depth of the non cyclic nodes using topo sort so that non cycilc nodes can be seperated from the cyclic nodes
    6. find nodes which connects the cycles and the non cyclic parts

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, query;
    cin >> n >> query;
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
    vector<int> c_depth(n + 1, 0);
    vector<int> cycle_touch(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int len = 0;
        if (vis[i] != 0)
            continue;
        int node = i;

        while (vis[node] != 2)
        {
            c_depth[node] = len;
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
    // 4. createing dp table for each nodes using binary lift
    vector<vector<int>> dp(n + 1, vector<int>(30, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = adj[i];
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    // cout<<c_length[1]<<endl;

    // 5. solving the query
    while (query--)
    {
        int a, b;
        cin >> a >> b;
        // 1. both don't lie in the same cycle
        if (cycle[a] != cycle[b])
        {
            cout << -1 << "\n";
            continue;
        }
        auto inCycledist = [&](int a, int b)
        {
            if (c_depth[a] <= c_depth[b])
            {
                return c_depth[b] - c_depth[a];
            }
            else
            {
                return c_length[cycle[a]] - (c_depth[a] - c_depth[b]);
            }
        };
        if (vis[b] == 2)
        {
            int dist = depth[a] - depth[cycle_touch[a]];
            // cout << dist << endl;
            dist += inCycledist(cycle_touch[a], b);
            cout << dist << endl;
            // cout << endl;
            continue;
        }
        if (vis[a] == 2)
        {
            cout << -1 << endl;
            continue;
        }
        if (cycle_touch[a] == cycle_touch[b] && depth[a] >= depth[b])
        {
            int dist = depth[a] - depth[b];
            int temp = dist;
            for (int i = 29; i >= 0; i--)
            {
                if (dist >= (1 << i))
                {
                    dist -= (1 << i);
                    a = dp[a][i];
                }
            }
            if (a == b)
            {
                cout << temp << endl;
                continue;
            }
        }
        cout << -1 << endl;
    }
}