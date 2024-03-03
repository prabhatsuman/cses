#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    int dp[n + 1][30];
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dp[i][0] = a;
    }
    for (int bit = 1; bit <= 29; bit++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][bit] = dp[dp[i][bit - 1]][bit - 1];
        }
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        for (int bit = 0; bit <= 29; bit++)
        {
            if (k & (1 << bit))
            {
                x = dp[x][bit];
            }
        }
        cout << x << endl;
    }
    return 0;
}