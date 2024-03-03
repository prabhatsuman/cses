#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vector<pair<int, int>> dp(1 << n, {INT_MAX, 0});

    function<pair<int, int>(int)> helper = [&](int mask)
    {
        if (mask == 0)
        {
            return dp[mask] = {1, 0};
        }
        if (dp[mask].first != INT_MAX)
        {
            return dp[mask];
        }
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                auto temp = helper(mask ^ (1 << i));
                if (temp.second + w[i] <= x)
                {
                    dp[mask] = min(dp[mask], {temp.first, temp.second + w[i]});
                }
                else
                {
                    dp[mask] = min(dp[mask], {temp.first + 1, w[i]});
                }
            }
        }
        return dp[mask];
    };
    cout << helper((1 << n) - 1).first << endl;
}