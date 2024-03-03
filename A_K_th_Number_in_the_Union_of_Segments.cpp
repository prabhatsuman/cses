#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    ll lo = -2e9, hi = 2e9;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (hi + lo) >> 1;
        // cout << mid << endl;

        function<ll(ll)> count = [&](ll mid)
        {
            ll cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (mid >= v[i].first)
                {
                    cnt += min(mid - v[i].first, v[i].second - v[i].first + 1);
                }
            }
            return cnt;
        };
        ll cnt = count(mid);
        // cout << cnt << endl;
        if (cnt <= k)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
}