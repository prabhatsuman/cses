/*
    Prabhat_007
*/
#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
#define nline '\n'
using namespace std;

typedef vector<int> vi;
#define all(v) (v).begin(), (v).end()
typedef vector<ll> vl;
#define read(v)       \
    for (auto &x : v) \
        cin >> x;

#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
void solve()
{
    //kmp algorithm
    string s;
    cin >> s;
    int n = s.length();
    string p;
    cin >> p;
    int m = p.length();
    //longest prefix suffix array
    vector<int> lps(m, 0);
    int i = 1;
    int len = 0;
    /*
    lps[i] = length of the longest proper prefix which is also a suffix of the string p[0...i] 
    Working of the LPS array:
    1. If p[i] == p[len] then lps[i] = len + 1
    2. If p[i] != p[len] then we need to find the longest proper prefix which is also a suffix of the string p[0...i-1]
    3. If len != 0 then len = lps[len-1]
    4. If len == 0 then lps[i] = 0
    5. Increment i
    */
    while (i < m)
    {
        if (p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    i = 0;
    int j = 0;
    int count = 0;
    /*
    Working of the KMP algorithm:
    1. If s[i] == p[j] then increment i and j
    2. If j == m then we have found a match increment count and set j = lps[j-1]
    3. If s[i] != p[j] then we need to find the longest proper prefix which is also a suffix of the string p[0...j-1]
    4. If j != 0 then j = lps[j-1]
    5. If j == 0 then increment i
    6. Increment i
    7. Repeat the above steps till i < n
    
    */
    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            count++;
            j = lps[j - 1];
        }
        else if (i < n && s[i] != p[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    cout << count << nline;
}

signed main()
{
    godspeed;
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}