#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
int main()
{
    std::ios::sync_with_stdio(false);
    string k;
    cin >> k;
    ll d;
    cin >> d;
    ll n = k.length();
    vector<vector<vector<ll>>> dp(n+5, vector<vector<ll>>(d+5, vector<ll>(2)));
    vector<vector<vector<bool>>> vis(n+5, vector<vector<bool>>(d+5, vector<bool>(2, false)));
    function<ll(ll, ll, ll)> helper = [&](ll ind, ll sum, ll tight) -> ll
    {
        if (ind == n)
        {
            return sum%d == 0;
        }
        ll& ans = dp[ind][sum][tight];
        ll digit = k[ind] - '0';
        // cout<<digit<<endl;
        if (vis[ind][sum][tight])
        {
            return ans;
        }
        vis[ind][sum][tight]=true;
        if (tight)
        {
            digit = 9;
        }
        for (ll i = 0; i <= digit; i++)
        {
            ans = (ans + helper(ind + 1, (sum+ i) % d, tight| (i<digit)))%mod;
        }
        return ans;
    };
    cout << (helper(0, 0, 0)%mod - 1%mod+mod)%mod << endl;
    return 0;
}
