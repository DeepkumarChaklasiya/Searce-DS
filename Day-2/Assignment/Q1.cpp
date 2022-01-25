/*
Definition : You have an empty sequence, and you will be given
			queries. Each query is one of these three types:
			1 x  -Push the element x into the stack.
			2    -Delete the element present at the top of the stack.
			3    -Print the maximum element in the stack.

Time complexity : O(number of query)

Space complexity : O(number of push query)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;
class MaxElement {
private:
	stack<int> s1;     /* This stack manages all elements */
	stack<int> s2;	   /* This stack manages max elements till current query so we can give answer in O(1) time */
public:
	void push(int x) {
		s1.push(x);
		if (s2.empty() or s2.top() <= x) s2.push(x);
	}
	void pop() {
		if (s1.top() == s2.top())  s2.pop();
		s1.pop();
	}
	int getMax() {
		return s2.top();
	}
};
int main()
{
	int q;
	cin >> q;
	MaxElement M;
	while (q--)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			int y;
			cin >> y;
			M.push(y);
		}
		else if (x == 2) M.pop();
		else cout << M.getMax() << endl;
	}
	return 0;
}