/*

Definition :	Find all triplets with zero sum

Time complexity : O(n^2)

Space complexity : O(n)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;

void findTriplet(int ar[], int n)
{
	bool flag = false;
	for (int i = 0; i < n - 1; i++)
	{
		unordered_map<int, int> mp;
		for (int j = i + 1; j < n; j++)
		{
			int x = -(ar[i] + ar[j]);
			if (mp.find(x) != mp.end())
			{
				cout << x << " " << ar[i] << " " << ar[j] << endl;
				flag = true;
			}
			else mp[ar[j]] = 1;
		}
	}
	if (flag == false) 	cout << "No Triplet" << endl;
}
int main()
{
	int n;
	cin >> n ;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	findTriplet(ar, n);
	return 0;
}