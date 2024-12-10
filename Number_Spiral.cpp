#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        if (x == y)
        {
            cout << x * x - x + 1;
        }
        else if (x > y)
        {
            if (x % 2 == 0)
            {
                cout << x * x - y + 1;
            }
            else
            {
                cout << (x - 1) * (x - 1) + y;
            }
        }
        else
        {
            if (y % 2 == 0)
            {
                cout << (y - 1) * (y - 1) + x;
            }
            else
            {
                cout << y * y - x + 1;
            }
        }
        cout<<endl;
    }
    return 0;
}