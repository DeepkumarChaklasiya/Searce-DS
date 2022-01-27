/*

Definition :Given an array and an integer k, find the count of distinct elements in every subarray of size k.
Time complexity : O(n)

Space complexity : O(n)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;

void findDistinctCount(int ar[], int n, int k)
{
	// map to store the frequency of elements of the window size k
	unordered_map<int, int>mp;
	// maintains the count of distinct elements of the window size k
	int distinct = 0;
	for (int i = 0; i < n; i++) {
		// just add first k elements
		if (i >= k)
		{
			// remove the first element from the subarray by reducing its frequency in the map
			mp[ar[i - k]]--;
			// decrease the distinct count if frequenct left with 0
			if (mp[ar[i - k]] == 0) {
				distinct--;
			}
		}

		// add the current element
		mp[ar[i]]++;

		// increment distinct count by 1 if frequency become one of the element
		if (mp[ar[i]] == 1) {
			distinct++;
		}
		if (i >= k - 1)
		{
			cout << distinct << endl;
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	findDistinctCount(ar, n, k);
	return 0;
}