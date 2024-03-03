#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    vector<int> deadline(n);
    vector<int> duration(n);
    for(int i=0;i<n;i++)
    {
        cin>> duration[i];
        cin>> deadline[i];
    }
    sort(duration.begin(),duration.end());
    vector<ll> pre(n,0);
    pre[0]=duration[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+duration[i];
    }
    ll ans=accumulate(deadline.begin(),deadline.end(),0LL);
    for(int i=0;i<n;i++)
    {
        ans-=pre[i];
    }
    cout<<ans<<endl;
    
}