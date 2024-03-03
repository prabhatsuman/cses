#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    vector<vector<bool>> dp(n + 1, vector<bool>(1e5 + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1e5; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1])
                dp[i][j] = dp[i][j] | dp[i - 1][j - v[i - 1]];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= 1e5; i++)
    {
        if (dp[n][i])
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}