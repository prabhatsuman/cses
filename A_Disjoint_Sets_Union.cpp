#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1);    
    vector<int> size(n+1,1);
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    function<int(int)> find=[&](int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    };
    function<void(int,int)> unite=[&](int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(size[a]<size[b])
                swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    };
    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        if(s=="union")
        {
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        else
        {
            int a,b;
            cin>>a>>b;
            if(find(a)==find(b))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}