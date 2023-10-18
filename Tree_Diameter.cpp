/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;
ll count_of_digits(ll n);
ll sum_of_digits(ll n);
ll power(int a, int b);
typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define read(v)       \
    for (auto &x : v) \
        cin >> x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define printp(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i].first << " " << v[i].second << nline;
#define printm(m)                                  \
    for (auto it = m.begin(); it != m.end(); it++) \
        cout << it->first << " " << it->second << nline;
#define prints(s)                                  \
    for (auto it = s.begin(); it != s.end(); it++) \
        cout << *it << " ";
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

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
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> height(n + 1, 0);
    function<int(int, int)> dfs = [&](int node, int par)
    {
        int ans = 0;
        if (height[node] != 0)
        {
            return height[node];
        }
        for (auto child : adj[node])
        {
            if (child != par)
            {
                ans = max(ans, dfs(child, node) + 1);
            }
        }
        return height[node] = ans;
    };
    dfs(1, 0);
    // printv(height);
    // cout << endl;

    vector<int> dp(n + 1, 0);
    function<void(int, int)> dfs2 = [&](int node, int par)
    {
        priority_queue<int> pq;
        int ans=0;
        for(auto child:adj[node])
        {
            if(child!=par)
            {                
                pq.push(height[child]);
            }
        }
        if(pq.size()>=2)
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            ans=2+first+second;
        }
        else if(pq.size()==1)
        {
            ans=1+pq.top();
        }
        dp[node]=ans;
        for(auto child:adj[node])
        {
            if(child!=par)
            {
                // cout<<node<<" "<<child<<nline;
                // cout<<dp[child]<<nline;
                dfs2(child,node);
                dp[node]=max(dp[node],dp[child]);
            }
        }


        
       
    };
    dfs2(1, 0);
    // printv(dp);
    // cout << endl;
    cout << dp[1] << nline;
}

int main()
{
    godspeed;
    ll t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}
ll sum_of_digits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
ll count_of_digits(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
ll power(int a, int b)
{
    if (b == 0)
        return 1;
    ll res = power(a, b / 2);
    if (b & 1)
    {
        return (a * (res * res) % M) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
