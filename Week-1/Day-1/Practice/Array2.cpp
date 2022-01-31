/*
Time complexity : O(n)
Space complexity : O(n)
Problem link:	"https://leetcode.com/problems/solving-questions-with-brainpower/"
Author : Deep Chaklasiya
*/


#include<bits/stdc++.h>
using namespace std;
int mostPoint(int ar[][2], int n)
{
	int point[200005];
	memset(point, 0, sizeof(point));
	for (int i = n - 1; i >= 0; i--)
	{
		int ttl = i + ar[i][1] + 1;
		point[i] = max(point[i + 1], ar[i][0] + point[ttl]);
	}
	return point[0];
}
int main()
{
	int n;
	cin >> n;
	int ar[n][2];
	for (int i = 0; i < n; i++) cin >> ar[i][0] >> ar[i][1];
	cout << mostPoint(ar, n);
	return 0;
}