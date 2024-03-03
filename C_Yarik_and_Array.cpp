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
    int n;
    cin >> n;
    vi v(n);
    read(v);
    vector<vector<int>> sub;
    vector<int> temp;
    temp.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (abs(v[i] % 2) == abs(v[i - 1] % 2))
        {
            sub.pb(temp);
            temp.clear();
            temp.push_back(v[i]);
        }
        else
        {
            temp.push_back(v[i]);
        }
    }
    sub.push_back(temp);
    // print2d(sub);
    int ans = -1e9;
    function<int(vector<int>)> solve = [&](vector<int> v)
    {
        int mx_sum = -1e9;
        int curr = 0;
        for (int i = 0; i < v.size(); i++)
        {
            curr=max(curr+v[i],v[i]);
            mx_sum=max(mx_sum,curr);
        }
        return mx_sum;
    };
    for (int i = 0; i < sub.size(); i++)
    {
       ans=max(ans,solve(sub[i]));
    }
    print(ans);
}

int main()
{
    godspeed;
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
