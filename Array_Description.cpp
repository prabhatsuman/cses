#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (v[i - 1] == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if (v[i - 1] == j)
                    {
                        dp[i][j] = 1;
                    }
                }
                continue;
            }
            if (v[i - 1] == 0)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % mod;
            }
            else
            {
                if (v[i - 1] == j)
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1] + dp[i][j]) % mod;
                }
            }
        }
    }

    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum = (sum+dp[n][i])%mod;
    }
    cout<<sum;
    return 0;
}

