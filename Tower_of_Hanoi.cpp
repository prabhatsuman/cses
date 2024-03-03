#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int moves=pow(2,n)-1;
    cout<<moves<<endl;
    function<void(int,int ,int,int)> toh =[&](int n,int src,int dst,int helper)
    {
        if(n==0)
        {
            return ;
        }
        toh(n-1,src,helper,dst);
        cout<<src<<" "<<dst<<endl;
        toh(n-1,helper,dst,src);
    };
    toh(n,1,3,2);

    
}