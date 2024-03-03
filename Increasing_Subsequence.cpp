#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        auto it = mp.lower_bound(v[i]);
        if (it == mp.begin())
        {
            mp[v[i]] = 1;
        }
        else
        {
            it--;
            int len = it->second + 1;
            mp[v[i]] = len;
            auto it2 = mp.upper_bound(v[i]);
            while (it2 != mp.end() && it2->second <= len)
            {
                auto temp = it2;
                temp++;
                mp.erase(it2);
                it2 = temp;
            }
        }
    }
    int ans = 0;
    for (auto i : mp)
    {
        ans = max(ans, i.second);
    }
    cout << ans << endl;
}