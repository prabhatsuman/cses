/*
    Prabhat_007
*/
#include <bits/stdc++.h>
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
        cout << v[i] << " ";
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
class SegmentTree{
    vector<ll> tree;
    int n; 
    public:
    SegmentTree(int n,vector<int> &v)
    {
        this->n=n;
        tree.resize(4*n);
        build(v,0,n-1,0);
    }
    void build(vector<int> &v,int start,int end,int node)
    {
        if(start==end)
        {
            tree[node]=v[start];
            return;
        }
        int mid=(start+end)/2;
        build(v,start,mid,2*node+1);
        build(v,mid+1,end,2*node+2);
        tree[node]=tree[node*2+1]+tree[node*2+2];
    }
    ll  query(int left, int right)
    {
        return Query(left,right,0,n-1,0);
    }
    ll Query(int left, int right, int start,int end, int node)
    {
        if(left<=start && right>=end)
        {
            return tree[node];
        }
        if(left>end || right<start)
        {
            return 0;
        }
        int mid=(start+end)>>1;
        ll ans1=Query(left,right,start,mid,2*node+1);
        ll ans2=Query(left,right,mid+1,end,2*node+2);
        return ans1+ans2;
    }
    void update(int index,int value)
    {
        Update(index,value,0,n-1,0);
    }
    void Update(int index,int value,int start,int end,int node)
    {
        if(start==end)
        {
            tree[node]=value;
            return;
        }
        int mid=(start+end)>>1;
        if(index<=mid)
        {
            Update(index,value,start,mid,2*node+1);
        }
        else
        {
            Update(index,value,mid+1,end,2*node+2);
        }
        tree[node]=tree[node*2+1]+tree[node*2+2];
        
    }

};
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    read(v);
    SegmentTree st(n,v);
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            st.update(b-1,c);
            v[b-1]=c;
        }
        else
        {
            cout<<st.query(b-1,c-1)<<nline;
        }
    }

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
