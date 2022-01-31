/*
Definition : Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Time complexity : O(n)
Space complexity : O(k)
Author : Deep Chaklasiya
*/


#include<bits/stdc++.h>
using namespace std;

void maxSlidingWindow(int ar[], int k, int n)
{
	deque<int>dq;
	for (int i = 0; i < n; i++) {
		if (!dq.empty() && dq.front() == i - k) dq.pop_front();
		while (!dq.empty() && ar[dq.back()] < ar[i])
			dq.pop_back();

		dq.push_back(i);
		if (i >= k - 1) cout << ar[dq.front()] << " ";
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	cout << "Maximum element in every " << k << " window " << endl;
	maxSlidingWindow(ar, k, n);
	return 0;
}