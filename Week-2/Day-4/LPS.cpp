/*

Definition :Given a string s, return the longest palindromic substring in s.

Problem link:https://leetcode.com/problems/longest-palindromic-substring/

TC : O(n^2)

SC : O(n^2)

Topic  : Dynamic Programming

*/


#include<bits/stdc++.h>
using namespace std;

string Lps(string s)
{
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    /*

    dp[i][j] =  0 if substring between i to j is not pallindrome

    dp[i][j] =  1 if substring between i to j is pallindrone

    This is bottom-up approach.

    */


    for (int i = 0; i < n; i++) dp[i][i] = 1;
    int len = 1, index = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j - i == 1)
            {
                if (s[i] == s[j])
                {
                    if (len == 1)
                    {
                        len = 2;
                        index = i;
                    }
                    dp[i][j] = 1;
                }
            }
            else if (dp[i + 1][j - 1] && s[i] == s[j])
            {
                if (len < j - i + 1) {
                    len = j - i + 1;
                    index = i;
                }
                dp[i][j] = 1;
            }
        }
    }
    return s.substr(index, len);
}

int main()
{
    string s;
    cin >> s;
    cout << Lps(s);
}