#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    multiset<int> left, right;
    function<void(int)> insert = [&](int x)
    {
        int top = *left.rbegin();
        if (top < x)
        {
            right.insert(x);
            if (right.size() > k / 2)
            {
                left.insert(*right.begin());
                right.erase(right.find(*right.begin()));
            }
        }
        else
        {
            left.insert(x);
            if (left.size() > (k + 1) / 2)
            {
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }
        }
    };
    function<void(int)> erase = [&](int x)
    {
        if (left.find(x) != left.end())
        {
            left.erase(left.find(x));
        }
        else
        {
            right.erase(right.find(x));
        }
        if (left.size() < (k + 1) / 2)
        {
            left.insert(*right.begin());
            right.erase(right.find(*right.begin()));
        }
    };
    left.insert(v[0]);
    for (int i = 1; i < k; i++)
    {
        insert(v[i]);
    }
    cout << *left.rbegin() << " ";
    for (int i = k; i < n; i++)
    {
        if (k == 1)
        {
            insert(v[i]);
            erase(v[i - k]);
            cout << *left.rbegin() << " ";
            continue;
        }
        erase(v[i - k]);
        insert(v[i]);
        cout << *left.rbegin() << " ";
    }
    cout << endl;
}