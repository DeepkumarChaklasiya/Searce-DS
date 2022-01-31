/*
Definition : Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
Time complexity : O(log n)
Space complexity : O(1)
Problem link:	"https://leetcode.com/problems/find-peak-element/"
Author : Deep Chaklasiya
*/


#include<bits/stdc++.h>
using namespace std;
int peakElement(int ar[], int n)
{
	/*

	Logic : Apply binary search for finding answer

	*/
	for (int i = 1; i < n; i++)
	{
		if (ar[i] < ar[i - 1]) return i - 1;
	}
	return n - 1;
}
int main()
{
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	cout << peakElement(ar, n);
	return 0;
}