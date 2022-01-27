/*

Definition :find the number of subarray which has sum zero.

Time complexity : O(n)

Space complexity : O(n)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;

int subArray(int ar[], int n)
{
	int ans = 0, tmpsum = 0;
	unordered_map<int, int>mp;
	/*	Initially number of subrray with zero sum is 1 that is empty array		*/
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		tmpsum += ar[i];
		// if the sum is seen before, increment our answer by number of seen
		if (mp.find(tmpsum) != mp.end())
		{
			ans += mp[tmpsum];
		}
		//increment the frequency of sum by 1
		mp[tmpsum] += 1;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n ;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	cout << subArray(ar, n);
	return 0;
}