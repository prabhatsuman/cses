#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if(n<=3 && n!=1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for(int i=2; i<=n; i+=2)
    {
        cout << i << " ";
    }
    for(int i=1; i<=n; i+=2)
    {
        cout << i << " ";
    }
    cout << endl;
  
    return 0;
}