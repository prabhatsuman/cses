#include <bits/stdc++.h>
using namespace std;
struct query
{
    string s;
    int a, b;
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> parent(n + 1);
    vector<int> size(n + 1, 1);
    vector<query> q(k);
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> q[i].s;
        cin >> q[i].a;
        cin >> q[i].b;
    }
    reverse(q.begin(), q.end());
    vector<string> ans;
    function<int(int)> find = [&](int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x]= find(parent[x]);
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
        }
    };
    for(int i=0;i<k;i++)
    {
        if(q[i].s=="ask")
        {
            if(find(q[i].a)==find(q[i].b))
            {
                ans.push_back("YES");
            }
            else
            {
                ans.push_back("NO");
            }
        }
        else
        {
            unite(q[i].a,q[i].b);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<"\n";
    }
    return 0;

}