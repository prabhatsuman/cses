#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
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
    
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << n, -1));
  
    function<ll(int, int)> helper = [&](int node, int bit) -> ll
    {
        if (node == n)
        {
            return binpow(2, n) - 1 == bit;
        }
        if (dp[node][bit] != -1)
        {
            return dp[node][bit];
        }
        ll ans = 0;
        for (auto child : adj[node])
        {
            if ((bit & (1 << (child - 1))) == 0)
            {
                ans = (ans + helper(child, bit | (1 << (child - 1)))) % mod;
            }
        }
        return dp[node][bit] = ans;
    };
    cout << helper(1, 1) << endl;
}