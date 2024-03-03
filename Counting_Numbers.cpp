#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll r, t;
    cin >> r >> t;
    r--;
    string a = to_string(r);
    string b = to_string(t);
    int m = a.length();
    int n = b.length();
    ll dp1[n + 1][12][2][2];
    ll dp2[m + 1][12][2][2];
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    function<ll(int, int, int, int)> helper1 = [&](int ind, int last, int tight, int lead_zero) -> ll
    {
        if (ind == n)
        {
            return 1;
        }
        if (dp1[ind][last + 1][tight][lead_zero] != -1)
        {
            return dp1[ind][last + 1][tight][lead_zero];
        }
        ll ans = 0;
        int digit = b[ind] - '0';
        if (tight)
        {
            digit = 9;
        }
        for (int i = 0; i <= digit; i++)
        {
            if (lead_zero && i == 0)
            {
                ans += helper1(ind + 1, i, tight | (i < digit), true);
                continue;
            }

            if (i != last)
            {
                ans += helper1(ind + 1, i, tight | (i < digit), false);
            }
        }
        return dp1[ind][last + 1][tight][lead_zero] = ans;
    };
    function<ll(int, int, int, int)> helper2 = [&](int ind, int last, int tight, int lead_zero) -> ll
    {
        if (ind == m)
        {
            return 1;
        }
        if (dp2[ind][last + 1][tight][lead_zero] != -1)
        {
            return dp2[ind][last + 1][tight][lead_zero];
        }
        ll ans = 0;
        int digit = a[ind] - '0';
        if (tight)
        {
            digit = 9;
        }
        for (int i = 0; i <= digit; i++)
        {
            if (lead_zero && i == 0)
            {
                ans += helper2(ind + 1, i, tight | (i < digit), true);
                continue;
            }

            if (i != last)
            {
                ans += helper2(ind + 1, i, tight | (i < digit), false);
            }
        }
        return dp2[ind][last + 1][tight][lead_zero] = ans;
    };

    ll ans1 = helper1(0, -1, 0, 1);
    ll ans2 = helper2(0, -1, 0, 1);
    cout << ans1 - ans2;

    return 0;
}