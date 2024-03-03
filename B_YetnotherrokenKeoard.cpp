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
    string s;
    cin>>s;
    priority_queue<pair<int,char>> pq1,pq2;
    for(int i=0;i<s.size();i++)
    {
        if(isupper(s[i]) && s[i]!='B')
        {
            pq1.push({i,s[i]});
        }
        else if(islower(s[i]) && s[i]!='b')
        {
            pq2.push({i,s[i]});

        }
        if(s[i]=='b' && pq2.size()>0)
        {
            pq2.pop();
        }
        else if(s[i]=='B' && pq1.size()>0)
        {
            pq1.pop();
        }
    }
    vector<pair<int,char>> v1;
    while(!pq1.empty())
    {
        v1.push_back(pq1.top());
        pq1.pop();
    }
    while(!pq2.empty())
    {
        v1.push_back(pq2.top());
        pq2.pop();
    }
    sort(all(v1));
    for(auto x:v1)
    {
        cout<<x.second;
    }
    cout<<nline;
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
