/*

Definition :Given an unsorted integer array, find a pair with the given sum in it.

Time complexity : O(n)

Space complexity : O(n)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;

void findPair(int ar[], int n, int sum)
{
	unordered_map<int, int>mp;
	for (int i = 0; i < n; i++) {
		// if the difference is seen before, print the pair
		if (mp.find(sum - ar[i]) != mp.end())
		{
			cout << "Pair found : " << ar[mp[sum - ar[i]]] << " " << ar[i];
			return;
		}
		// store index of the current element in the map
		mp[ar[i]] = i;
	}
	cout << "Pair not found :(";
}
int main()
{
	int n, sum;
	cin >> n >> sum;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	findPair(ar, n, sum);
	return 0;
}