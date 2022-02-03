/*

Definition :There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Problem link: https://leetcode.com/problems/unique-paths/

TC : O(n^2)

SC : O(n^2)

Topic  : Dynamic Programming

*/


#include<bits/stdc++.h>
using namespace std;

int UniquePath(int n, int m)
{
    int dp[n][m];
    memset(dp, 0, sizeof(dp));

    /*

    dp[i][j] =  Number of unique path between (0,0) to (i,j)
    dp[n-1][m-1] = our final result
    */
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) continue;
            if (i == 0) dp[i][j] += dp[i][j - 1];
            else if (j == 0) dp[i][j] += dp[i - 1][j];
            else dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << UniquePath(n, m);
}