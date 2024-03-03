#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int

signed main()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0)
            {
                dp[i][j] = (dp[i][j] % mod + dp[i - 1][left] % mod) % mod;
            }
        }
    }
    cout << (dp[n][sum]%mod*500000004%mod)%mod << endl;
    return 0;
}