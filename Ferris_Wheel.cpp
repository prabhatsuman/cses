#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int i = 0, j = n - 1;
    int cnt = n;
    while (i < j)
    {
        if (v[i] + v[j] <= x)
        {
            cnt-=2;
            i++;
            j--;
            ans++;
        }
        else
        {
            j--;
        }
    }
    ans+=cnt;
    cout << ans << endl;
}