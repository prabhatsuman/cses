#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    function<int(int, int)> dfs = [&](int i, int j)
    {
        if (i >= n || j >= n || v[i][j] == '*')
        {
            return 0;
        }
        if (i == n - 1 && j == n - 1)
        {
            return 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = (dfs(i + 1, j) % mod + dfs(i, j + 1) % mod) % mod;
    };
    cout << dfs(0, 0);
    return 0;
}