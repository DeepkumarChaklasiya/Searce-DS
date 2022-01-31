/*
Definition : Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn’t exist, return -1 for this element.
Time complexity : O(n)
Space complexity : O(n)
Author : Deep Chaklasiya
*/


#include<bits/stdc++.h>
using namespace std;

void nextGreater(int ar[], int n)
{
	int nge[n];
	memset(nge, -1, sizeof(nge));
	stack<int>s;
	for (int i = 2 * n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= ar[i % n]) {
			s.pop();
		}
		if (i < n) {
			if (!s.empty()) nge[i] = s.top();
		}
		s.push(ar[i % n]);
	}
	for (int i = 0; i < n; i++) cout << nge[i] << " ";
}

int main()
{
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) cin >> ar[i];
	nextGreater(ar, n);
	return 0;
}