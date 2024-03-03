#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    function<int(int)> find_parent = [&](int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node]);
    };
    function<void(int, int)> union_nodes = [&](int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        if (a != b)
        {
            parent[b] = a;
        }
    };
    ll cost = 0;
    for (auto edge : edges)
    {
        int a = edge.second.first;
        int b = edge.second.second;
        int c = edge.first;
        if (find_parent(a) != find_parent(b))
        {
            union_nodes(a, b);
            cost += c;
        }
    }
    int count = 1;
    int curr = find_parent(1);
    for (int i = 2; i <= n; i++)
    {
        if (find_parent(i) != curr)
        {
            count++;
        }
    }
    if (count > 1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << cost << "\n";

    return 0;
}