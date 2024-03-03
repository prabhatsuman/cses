#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> radj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);
    function<void(int,vector<int> [])> dfs=[&](int node,vector<int> adj[])->void
    {
        vis[node]=true;
        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                dfs(child,adj);
            }
        }

    };
    dfs(1,adj);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<1<<" "<<i<<endl;
            return 0;
        }
    }
    vis.assign(n+1,false);
    dfs(1,radj);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout<<i<<" "<<1<<endl;
            return;
        }
    }
    

}