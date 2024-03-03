#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int lo = a[0] + b[0], hi = a[n - 1] + b[n - 1];
    int ans = 0;
    function<int(int)> count = [&](int mid)
    {
        int cnt = 0;
        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && a[i] + b[j] > mid)
            {
                j--;
            }
            cnt += j + 1;
        }
        return cnt;
    };
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;
        int cnt = count(mid);
        if (cnt < k)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
   
    if(count(lo)>=k)
    {
        cout<<lo<<endl;
        return 0;
    }
    cout << hi << endl;
}
