/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
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
#define read(v) for(auto &x:v) cin>>x;
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";cout<<endl;
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
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        cin>>v[i][0];
        cin>>v[i][1];
        v[i][2]=i;
    }
    sort(all(v),[]
    
        (vector<int> a,vector<int> b)
        {
            if(a[0]==b[0])
            {
                return a[1]>b[1];
            }
            return a[0]<b[0];        
        }
    );
    // print2d(v);
    ordered_set st;
    vector<int> ans1(n);
    for(int i=n-1;i>=0;i--)
    {
        ans1[v[i][2]]=st.order_of_key({v[i][1]+1,-1})>0;
        st.insert({v[i][1],i});
        
    }
    st.clear();
    // printv(ans1);
    vector<int> ans2(n);
    for(int i=0;i<n;i++)
    {
        ans2[v[i][2]]=(i-st.order_of_key({v[i][1],-1}))>0;

        st.insert({v[i][1],i});
    }
    printv(ans1);
    printv(ans2);



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
