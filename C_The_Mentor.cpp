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


bool check(ll mid, vl &pos, vl &neg, ll k)
{
    ll pairct = 0;
    ll n1 = neg.size() - 1;
    ll p1 = pos.size() - 1;
    ll x = neg.size() - 1;
    
    for (int i = 0; i < neg.size(); i++)
    {
        while (x >= 0 && neg[i] * neg[x] <= mid)
        {
            x--;
        }
        pairct += min(n1 - x, n1 - i);
    }
    x = 0;
    for (int i = pos.size() - 1; i >= 0; i--)
    {
        while (x < pos.size() && pos[i] * pos[x] <= mid)
        {
            x++;
        }
        pairct += min(x, i*1LL);
    }

    x = pos.size() - 1;
    for (int i = neg.size() - 1; i >= 0; i--)
    {
        while (x >= 0 && neg[i] * pos[x] <= mid)
        {
            x--;
        }
        pairct += (p1 - x);
    }
    return pairct >= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vl v(n);
    read(v);
    vl pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (v[i]>= 0)
        {
            pos.pb(v[i]);
        }
        else
        {
            neg.pb(v[i]);
        }
    }
    sort(all(pos));
    sort(all(neg));
    ll l = -1e18, r = 1e18;
    ll ans = 0;
    while (l <= r)
    {
        ll mid = r-(r-l)/2;
     
        if (check(mid, pos, neg, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << nline;
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
