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
#define printv(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";           \
    cout << nline;
#define print2d(v)                            \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
            cout << v[i][j] << " ";           \
        cout << nline;                        \
    }
#define pb push_back
#define print(x) cout << x << nline;
#define print2(x, y) cout << x << " " << y << nline;
#define yes cout << "YES" << nline;
#define no cout << "NO" << nline;
#define godspeed                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

/* -----------------------------Code Begins from here-------------------------------------------*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'M')
            {
                q.push({{i, j}, 0});
                dist[i][j] = 0;
            }
        }
    }
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] != '#' && dist[nx][ny] > d + 1)
            {
                dist[nx][ny] = d + 1;
                q.push({{nx, ny}, d + 1});
            }
        }
    }
    vector<vector<char>> dir(n, vector<char>(m, '.'));
    vector<vector<bool>>vis(n,vector<bool> (m,false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                q.push({{i, j}, 0});
                dir[i][j]='*';
                vis[i][j]=true;
                break;
            }
        }
    }
    bool flag = false;
    int ans = 0;
    vector<char> temp = {'R', 'L', 'D', 'U'};
    int p = -1, r = -1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        {
            flag = true;
            ans = d;
            p = x;
            r = y;
        }
        for (int i = 0; i < 4; i++)
        {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (ax >= 0 && ax < n && ay >= 0 && ay < m && v[ax][ay] != '#' && v[ax][ay] != 'M' && dist[ax][ay] > d + 1 && !vis[ax][ay])
            {
                dir[ax][ay] = temp[i];
                vis[ax][ay]=true;
                q.push({{ax,ay},d+1});
            }
        }
    }
    if(!flag)
    {
        no;
        return;
    }
    // cout<<flag<<nline;
    char ct = dir[p][r];
    string res = "";
    while (ct != '*')
    {
        res += ct;
        if (ct == 'L')
        {
            r++;
        }
        else if (ct == 'R')
        {
            r--;
        }
        else if (ct == 'U')
        {
            p++;
        }
        else if (ct == 'D')
        {
            p--;
        }
        ct = dir[p][r];
    }
    // print2d(dir);

    if (flag)
    {
        yes;
        print(ans);
        reverse(all(res));
        cout << res << nline;
        return;
    }
    // no;
}

int main()
{
    godspeed;
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
