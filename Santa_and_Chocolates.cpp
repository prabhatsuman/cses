#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        int sum = accumulate(v.begin(), v.end(), 0);
        if (k == 0)
        {
            if (sum % n == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }

        if (sum >= n)
        {
            cout << "YES" << endl;
        }
        else

        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
