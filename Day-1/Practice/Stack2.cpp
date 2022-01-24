/*
Time complexity : O(n)
Space complexity : O(n)
Problem link:	"https://leetcode.com/problems/min-stack/"
Author : Deep Chaklasiya
*/

#include<bits/stdc++.h>
using namespace std;
class MinStack {
private:
	stack<int> s1;
	stack<int> s2;
public:
	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= getMin())  s2.push(x);
	}
	void pop() {
		if (s1.top() == getMin())  s2.pop();
		s1.pop();
	}
	int top() {
		return s1.top();
	}
	int getMin() {
		return s2.top();
	}
};
int main()
{
	int n;
	cin >> n;
	MinStack M;
	for (int i = 0; i < n; i++)
	{
		cout << "Press 1.push 2.pop 3.top element 4.Min element till now\n";
		int x;
		cin >> x;
		if (x == 1)
		{
			int y;
			cin >> y;
			M.push(y);
		}
		else if (x == 2) M.pop();
		else if (x == 3) cout << M.top() << endl;
		else cout << M.getMin() << endl;
	}
	return 0;
}