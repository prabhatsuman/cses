#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<int> size(n + 1, 1);
    vector<pair<int, int>> min_max(n + 1, {INT_MAX, INT_MIN});
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        min_max[i] = {i, i};
    }
    function<int(int)> find = [&](int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    };
    function<void(int, int)> unite = [&](int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            min_max[a].first = min(min_max[a].first, min_max[b].first);
            min_max[a].second = max(min_max[a].second, min_max[b].second);
        }
    };
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }
        else
        {
            int a;
            cin >> a;
            a = find(a);
            cout << min_max[a].first << " " << min_max[a].second << " " << size[a] << "\n";
        }
    }
}