/*
Definition : Reverse an array
Time complexity : O(n)
Space complexity : O(1)
Author : Deep Chaklasiya
*/


#include<bits/stdc++.h>
using namespace std;
void reverseArray(int ar[], int n)
{
	/*

	Logic : Linear traversal from start to mid of the array ,
			swap first element with last element ,
			swap second element with second last element ,
			swap third element with third last element ,
			this process repeats till mid of the array ,
			now array is reversed.

	*/
	for (int i = 0; i < n / 2; i++)
	{
		swap(ar[i], ar[n - i - 1]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	reverseArray(ar, n);
	return 0;
}