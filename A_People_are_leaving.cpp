#include <bits/stdc++.h>
using namespace std;
int main()
{
    //fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    function<int(int)> find = [&](int a) -> int
    {
        if (parent[a] == n + 1)
        {
            return n + 1;
        }
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = find(parent[a]);
    };

    for (int i = 1; i <= m; i++)
    {
        char c;
        cin >> c;
        if (c == '?')
        {
            int x;
            cin >> x;
            if (find(x) == n + 1)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << find(x) << '\n';
            }
        }
        else
        {
            int x;
            cin >> x;
            parent[x] = x + 1;
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
}