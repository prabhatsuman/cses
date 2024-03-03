#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // vector<pair<int, int>> edges;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(n + 1, 1);
    int max_size = 1;
    int comp = n;
    function<int(int)> find_par = [&](int u)
    {
        if (parent[u] == u)
        {
            return u;
        }
        return parent[u] = find_par(parent[u]);
    };
    function<void(int, int)> unite = [&](int u, int v)
    {
        int par_a = find_par(u);
        int par_b = find_par(v);
        // cout<<par_a<<" "<<par_b<<endl;
        
        if (par_a != par_b)
        {
            comp--;
            if (rank[par_a] > rank[par_b])
            {
                rank[par_a] += rank[par_b];
                parent[par_b] = par_a;
            }
            else
            {
                rank[par_b] += rank[par_a];
                parent[par_a] = par_b;
            }
        }
        // cout<<rank[par_a]<<" "<<rank[par_b]<<endl;
        // cout<<endl;
        max_size = max(max_size, rank[par_a]);
        max_size = max(max_size, rank[par_b]);
        cout << comp << " " << max_size << endl;
    };
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }
}