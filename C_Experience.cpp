#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<int> size(n + 1, 1);
    vector<ll> experience(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    function<int(int)> find = [&](int x)
    {
        if (parent[x] == x)
            return x;
        return find(parent[x]);
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
            experience[b] -= experience[a];
        }
    };
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        // cout<<s<<"\n";
        if (s == "join")
        {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }
        else if (s == "add")
        {
            int a, b;
            cin >> a >> b;
            a = find(a);

            experience[a] += b;
        }
        else
        {
            int a;
            cin >> a;
            int x = find(a);
            // cout << x << endl;
            ll sum = 0;
            while (a != x)
            {
                sum += experience[a];
                // cout << sum << " ";
                a = parent[a];
            }

            sum += experience[a];
            cout << sum << "\n";
        }
    }
}