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
#define int long long int
/* -----------------------------Code Begins from here-------------------------------------------*/
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    read(v);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    function<int(int, int)> helper = [&](int left, int right) -> int
    {
        if (left == right)
        {
            return v[left];
        }
        if (right - left == 1)
        {
            return max(v[left], v[right]);
        }
        if (dp[left][right] != -1)
            return dp[left][right];
        return dp[left][right] = max(v[left] + min(helper(left + 2, right), helper(left + 1, right - 1)), v[right] + min(helper(left, right - 2), helper(left + 1, right - 1)));
    };
    cout << helper(0, n - 1) << endl;
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
