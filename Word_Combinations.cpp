#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct TrieNode
{
    map<char, TrieNode *> children;
    bool isEndOfWord;
    TrieNode()
    {
        isEndOfWord = false;
    }
};

void insert(TrieNode *root, string word)
{
    TrieNode *curr = root;
    for (char ch : word)
    {
        if (curr->children.find(ch) == curr->children.end())
        {
            curr->children[ch] = new TrieNode();
        }
        curr = curr->children[ch];
    }
    curr->isEndOfWord = true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        insert(root, word);
    }
    int dp[s.size() + 1];
    memset(dp, 0, sizeof(dp));
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        TrieNode *curr = root;
        for (int j = i; j < s.size(); j++)
        {

            if (curr->children.find(s[j]) == curr->children.end())
            {
                break;
            }
            curr = curr->children[s[j]];
            if (curr->isEndOfWord)
            {
                dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
        }
    }
    cout << dp[0] << endl;
}