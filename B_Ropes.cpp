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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    read(v);
    double lo=0,hi=1e9;
    double eps=1e-6;
    while(hi-lo>eps)
    {
        double mid=lo+(hi-lo)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=(int)(v[i]/mid);
        }
        if(cnt>=k)
        {
            lo=mid;
        }
        else
        {
            hi=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<lo<<nline;
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
