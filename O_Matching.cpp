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
#define read(v) for(auto &x:v) cin>>x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";cout<<nline;
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
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<ll> dp(1<<n,0);
    dp[0]=1;
    for(int mask=0;mask<(1<<n)-1;mask++)
    {
        int temp=__builtin_popcount(mask);
        for(int j=0;j<n;j++)
        {
            if(mat[temp][j] && !(mask&(1<<j)))
            {
                dp[mask|(1<<j)]=(dp[mask]+dp[mask|(1<<j)])%M;
            }
        }
    }
    cout<<dp[(1<<n)-1];

}

int main()
{
    godspeed;
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
