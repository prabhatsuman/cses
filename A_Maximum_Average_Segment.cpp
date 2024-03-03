#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double lo = 0, hi = 101;
    function<bool(double)> check = [&](double mid)
    {
        vector<double> b(n);
        for (int i = 0; i < n; i++)
            b[i] = a[i] - mid;
        vector<double> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + b[i - 1];
        }
        vector<double> min_prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            min_prefix[i] = min(min_prefix[i - 1], prefix[i]);
        }
        for (int i = d; i <= n; i++)
        {
            if (prefix[i] - min_prefix[i - d] >= 0)
            {
                return true;
            }
        }
        return false;
    };
    double ans = -1;
    while (hi - lo > 1e-6)
    {
        double mid = lo + (hi - lo) / 2;
        // cout << mid << endl;
        if (check(mid))
        {
            ans = mid;
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if (ans == -1)
    {
        cout << 1 << " " << n << endl;
        return 0;
    }

    int left = -1, right = -1;
    vector<double> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i] - ans;
    vector<double> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + b[i - 1];
    }
    vector<double> min_prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        min_prefix[i] = min(min_prefix[i - 1], prefix[i]);
    }

    for (int i = d; i <= n; i++)
    {
        if (prefix[i] - min_prefix[i - d] >= 0)
        {
            right = i;
            double x = min_prefix[i - d];

            for (int j = i - d; j >= 0; j--)
            {
                if (prefix[j] == x)
                {
                    left = j + 1;
                    break;
                }
            }
            break;
        }
    }
    cout << left << " " << right << endl;

    return 0;
}