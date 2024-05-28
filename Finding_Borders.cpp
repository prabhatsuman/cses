#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    vector<int> lps(n+1,0);
    int i=1;
    int len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
    vector<int> ans;
    int j=lps[n-1];
    while(j>0)
    {
        ans.push_back(j);
        j=lps[j-1];
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
    

}