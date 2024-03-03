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
    vl v(n);
    read(v);
    vl pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+v[i-1];
    }
    ll ans=0;
    for(int k=1;k<=n;k++)
    {
        ll mi=1e18,mx=-1e18;
        if(n%k!=0)continue;
        for(int i=k;i<=n;i+=k)
        {
            mi=min(mi,pre[i]-pre[i-k]);
            mx=max(mx,pre[i]-pre[i-k]);
        }
        ans=max(ans,mx-mi);
        
    }
    cout<<ans<<endl;
    
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
