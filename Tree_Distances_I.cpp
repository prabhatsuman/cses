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
    vector<int> depth(n + 1, 0);
    function<void(int, int)> dfs = [&](int node, int par)
    {
        for (auto child : adj[node])
        {
            if (child != par)
            {
                dfs(child, node);
                depth[node] = max(depth[node], 1 + depth[child]);
            }
        }
    };
    dfs(1, 0);
    vector<int> ans(n + 1, 0);
    function<void(int, int, int)> solve = [&](int node, int par, int par_ans)
    {
       
        vector<int> preMax, sufMax;
        int c = 0;
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            preMax.pb(depth[child]);
            sufMax.pb(depth[child]);
            c++;
        }
      
      
        
        
        for (int i = 1; i < c; i++)
        {
            preMax[i] = max(preMax[i - 1], preMax[i]);
        }
        for (int i = c - 2; i >= 0; i--)
        {
            sufMax[i] = max(sufMax[i + 1], sufMax[i]);
        }
      
        c = 0; // child_nos
        for (auto child : adj[node])
        {
            if (child == par)
                continue;
            int c1 = (c == 0 ? -1e9 : preMax[c - 1]);
            int c2 = (c == preMax.size()-1 ? -1e9 : sufMax[c + 1]);
            // cout << c1 << " " << c2 << endl;
            int partial_ans = 1 + max({c1, c2, par_ans});
            solve(child, node, partial_ans);
            c++;
        }
        ans[node] = 1 + max(par_ans, (preMax.empty() ? -1 : preMax.back()));
    };
    solve(1, 0, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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
