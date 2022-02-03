/*

Definition :
            Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Problem link: https://leetcode.com/problems/word-break/

TC : O(((length of given string) ^ 2 )* (Dict size))

SC : O((length of given string))

Topic  : Dynamic Programming

*/


#include<bits/stdc++.h>
using namespace std;

int dp[305];

int WordBreak(string s, vector<string>&wordDict, int ind)
{
    if (ind == s.length())
    {
        return 1;
    }
    if (dp[ind] != -1) return dp[ind];
    for (int i = ind + 1; i <= s.length(); i++)
    {
        string subpart = s.substr(ind, i - ind);
        if (find(wordDict.begin(), wordDict.end(), subpart) != wordDict.end())
        {
            if (WordBreak(s, wordDict, i))
            {
                return dp[ind] = 1;
            }
        }
    }
    return dp[ind] = 0;
}
int main()
{
    string s;
    cin >> s;
    vector<string>v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string scan;
        cin >> scan;
        v.push_back(scan);
    }
    memset(dp, -1, sizeof(dp));
    cout << WordBreak(s, v, 0);
}