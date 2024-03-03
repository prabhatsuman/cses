#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &i:v)
    {
        cin>>i;
    }
    ll ans=0;
    map<int,int> mp;
    int left=0,right=0;
    while(right<n)
    {
        mp[v[right]]++;
        while(mp.size()>k)
        {
            mp[v[left]]--;
            if(mp[v[left]]==0)
            {
                mp.erase(v[left]);
            }
            left++;
        }
        ans+=(right-left+1);
        right++;
    }
    cout<<ans<<endl;
}