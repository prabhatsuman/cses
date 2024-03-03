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
struct Projects
{
    int start, end, value;
};

void solve()
{
    int n;
    cin >> n;
    vector<Projects> v;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    sort(v.begin(), v.end(), [&](Projects a, Projects b)
         { return a.start < b.start; });
  
    vector<int> start;

    for (int i = 0; i < n; i++)
    {
        start.push_back(v[i].start);
    }
    start.push_back(1e18);
    vector<int> dp(n + 1, -1);

    function<int(int)> helper = [&](int i) -> int
    {
        if (i == n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }

        int ans = helper(i + 1);
       
        int ind = upper_bound(start.begin(), start.end(), v[i].end) - start.begin();

        ans = max(ans, v[i].value + helper(ind));
        return dp[i]= ans;
    };
    cout << helper(0) << nline;
}

signed main()
{
    godspeed;
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
