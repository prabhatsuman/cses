/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
#define read(v)       \
    for (auto &x : v) \
        cin >> x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";           \
    cout << nline;
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define int long long 

/* -----------------------------Code Begins from here-------------------------------------------*/
void solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    adj[0].push_back(1);
    adj[1].push_back(0);
    int dp[n + 1][2];
    memset(dp, -1, sizeof(dp));
    function<int(int, int, int)> dfs = [&](int node, int par, int flag) -> int
    {
        int &ans = dp[node][flag];
        if (~ans)
        {
            return dp[node][flag];
        }
        ans = 1;
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            if (flag)
            {
                ans = (ans * (dfs(child, node, false) + dfs(child, node, true))) % M;
            }
            else
            {
                ans = (ans * dfs(child, node, true)) % M;
            }
        }
        return ans;
    };
    int ans = dfs(1, 0, true) + dfs(1, 0, false);
    ans %= M;
    cout << ans << endl;
}

signed main()
{
    godspeed;
    ll t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
