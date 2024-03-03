#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - coins[i - 1] >= 0)
            {
                dp[i][j] = (dp[i][j - coins[i - 1]] + dp[i - 1][j]) % 1000000007;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][x];


}