#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    int lo = 0, hi = 1e9;
    function<bool(int)> check = [&](int mid)
    {
        int cnt = 1;
        int last = v[0];
        // cout<<mid<<endl;
        for (int i = 1; i < n; i++)
        {
            if (v[i] - last >= mid)
            {
                cnt++;
                last = v[i];
            }
        }
        // cout<<cnt<<endl;
        return cnt >= k;
    };
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    // cout << lo << " " << hi << endl;
    if (check(hi))
    {
        cout << hi << endl;
        return 0;
    }
    cout << lo << endl;
    return 0;
}