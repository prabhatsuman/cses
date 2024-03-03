#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    multiset<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    vector<int> people(m);
    for(auto &it:people)
    {
        cin>>it;
    }
    for(int i=0;i<m;i++)
    {
        auto x=s.upper_bound(people[i]);
        if(x==s.begin())
        {
            cout<<-1<<endl;
        }
        else
        {
            x--;
            cout<<*x<<endl;
            s.erase(x);
        }
    }
    
}