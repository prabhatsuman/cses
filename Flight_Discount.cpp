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
auto cmp = [](vector<ll> a, vector<ll> b)
{
    return a[0] < b[0];
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        // adj[v].pb({u, w});
    }
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
    pq.push({0, {1, 1}});
    vector<ll> dist(n + 1, 1e18);
    vector<ll> dist1(n + 1, 1e18);
    dist[1] = 0;
    dist1[1] = 0;
    while (!pq.empty())
    {
        ll node = pq.top().second.first;
        ll cost = pq.top().first;
        ll flag = pq.top().second.second;
        pq.pop();
        if(flag)
        {
            if(dist[node]<cost)
                continue;
        }
        else
        {
            if(dist1[node]<cost)
                continue;
        }
        // cout<<flag<<nline;
        if (flag)
        {
            for (auto child : adj[node])
            {
                if (dist[child.first] > cost + child.second)
                {
                    dist[child.first] = cost + child.second;
                    pq.push({dist[child.first], {child.first, 1}});
                }
                if (dist1[child.first] > cost + child.second / 2)
                {
                    dist1[child.first] = cost + child.second / 2;
                    pq.push({dist1[child.first],{ child.first, 0}});
                }
            }
        }
        else
        {
            for (auto child : adj[node])
            {
                if (dist1[child.first] > cost + child.second)
                {
                    dist1[child.first] = cost + child.second;
                    pq.push({dist1[child.first], {child.first, 0}});
                }
            }
        }
    }

    cout << min(dist1[n],dist[n]) << nline;
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
