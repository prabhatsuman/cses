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

#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
class BIT
{
public:
    vector<int> bit;
    int n;
    BIT(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    void update(int idx, int val)
    {
        for (; idx < n; idx += (idx & -idx))
        {
            bit[idx] += val;
        }
    }
    int query(int idx)
    {
        int ans = 0;
        for (; idx > 0; idx -= (idx & -idx))
        {
            ans += bit[idx];
        }
        return ans;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    BIT bit(n + 1);
    for (int i = 1; i <= n; i++)
    {
        bit.update(i, 1);
    }
    debug(bit.bit);
    for (int i = 0; i < n; i++)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (bit.query(mid) >= q[i])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << v[l - 1] << " ";
        bit.update(l, -1);
    }
}

signed main()
{
    godspeed;
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
