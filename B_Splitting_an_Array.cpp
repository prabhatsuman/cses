#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int lo = *max_element(a.begin(), a.end()), hi = accumulate(a.begin(), a.end(),0LL);
    function<bool(int)> check = [&](int mid)
    {
        int sum = 0, cnt = 1;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum > mid)
            {
                cnt++;
                sum = a[i];
            }
        }
        // cout << mid << " " << cnt << endl;
        return cnt <= k;
    };
    while (hi - lo > 1)
    {
        int mid = (hi + lo) >> 1;

        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if (check(lo))
    {
        cout << lo << endl;
        return 0;
    }
    cout << hi << endl;
}