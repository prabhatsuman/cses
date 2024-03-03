#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> disc(n + 1, -1);
    vector<int> low(n + 1, -1);
    stack<int> st;
    vector<bool> inStack(n + 1, false);
    vector<int> ans(n + 1, 0);

    int timer = 0;
    int comp = 0;
    function<void(int)> dfs = [&](int node)
    {
        disc[node] = low[node] = timer;
        timer++;
        st.push(node);
        inStack[node] = true;
        for (auto child : adj[node])
        {

            if (disc[child] == -1)
            {

                dfs(child);
                low[node] = min(low[node], low[child]);
            }
            else
            {
                if (inStack[child])
                {
                    low[node] = min(low[node], disc[child]);
                }
            }
        }
        if (disc[node] == low[node])
        {
            

            comp++;
            while (st.top() != node)
            {
                int x = st.top();
                st.pop();
                ans[x] = comp;
                inStack[x] = false;
            }
            ans[node] = comp;
            st.pop();
            inStack[node] = false;
        }
    };
    for(int i=1;i<=n;i++)
    {
        if(disc[i]==-1)
         dfs(i);
    }
    cout << comp << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}