#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    ll lo = *max_element(v.begin(), v.end());
    ll hi = accumulate(v.begin(), v.end(), 0LL);
    function<bool(ll)> check = [&](ll mid) -> bool
    {
        ll sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum + v[i] > mid)
            {
                sum = v[i];
                cnt++;
            }
            else
            {
                sum += v[i];
            }
        }
       
        return cnt <= k;
    };
    while (hi - lo > 1)
    {
        ll mid = hi - (hi - lo) / 2;
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
    }
    else
    {
        cout << hi << endl;
    }
}