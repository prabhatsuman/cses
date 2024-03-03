#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    int lo = 0, hi = 1e9;
    function<bool(int)> check = [&](int mid)
    {
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr.first == n)
            {
                return true;
            }
            for (auto child : adj[curr.first])
            {
                if (child.second <= mid && curr.second < d && !vis[child.first])
                {
                    vis[child.first] = true;
                    q.push({child.first, curr.second + 1});
                }
            }
        }
        return false;
    };

    int ans = -1;
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;
        // cout<<mid<<endl;
        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if (check(lo))
    {
        ans = lo;
        // return 0;
    }
    else if (check(hi))
    {
        ans = hi;
    }
    else
    {
        cout << ans << endl;
        return 0;
    }

    queue<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    q.push({1, 0});
    vis[1] = true;
    vector<int> parent(n + 1, -1);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr.first == n)
        {
            vector<int> path;
            int node = n;
            while (node != -1)
            {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            cout << path.size() - 1 << endl;
            for (auto x : path)
            {
                cout << x << " ";
            }
            cout << endl;
            return 0;
        }
        for (auto child : adj[curr.first])
        {
            if (child.second <= ans && curr.second < d && !vis[child.first])
            {
                vis[child.first] = true;
                if (parent[child.first] == -1)
                    parent[child.first] = curr.first;
                q.push({child.first, curr.second + 1});
            }
        }
    }

    return 0;
}