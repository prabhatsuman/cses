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
    int n, q;
    cin >> n >> q;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int a;
        cin >> a;
        adj[i + 2].pb(a);
        adj[a].pb(i + 2);
    }
    vector<vector<int>> dp(n + 1, vector<int>(20, -1));
    function<void(int, int)> dfs = [&](int node, int par)
    { 
        dp[node][0] = par;
        for (int i = 1; i < 20; i++)
        {
            if (dp[node][i - 1] != -1)
                dp[node][i] = dp[dp[node][i - 1]][i - 1];
        }
        for (auto child : adj[node])
        {
            if (child != par)
            {
                dfs(child, node);
            }
        }
    };
    dfs(1,-1);

    
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int i = 0;
        while (k > 0)
        {

            if (x != -1 && (k&1))
            {
                x = dp[x][i];
            }
            i++;
            k >>= 1;
        }
        cout << x << endl;
    }
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
