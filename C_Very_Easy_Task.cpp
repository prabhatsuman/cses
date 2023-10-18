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

/* -----------------------------Code Begins from here-------------------------------------------*/
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    ll lo = 1, hi = max(x, y) * n;
    while (hi - lo > 1)
    {
        ll mid = hi - (hi - lo) / 2;
        function<bool(ll)> check = [&](ll mid)
        {
            if (mid < min(x, y))
            {
                return false;
            }
            ll rem = mid - min(x, y);
            return (rem / x + rem / y + 1 >= n);
        };
        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    cout << hi << nline;
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
