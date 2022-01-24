/*
Time complexity : O(n)
Space complexity : O(n)
Problem link:	"https://leetcode.com/problems/valid-parentheses/"
Author : Deep Chaklasiya
*/

#include<bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
	stack<int>st;
	map<char, char>mp;
	mp['('] = ')';
	mp['{'] = '}';
	mp['['] = ']';
	for (int i = 0; i < s.size(); i++)
	{
		if (st.empty() or s[i] == '(' or s[i] == '[' or s[i] == '{')
			st.push(s[i]);
		else if (mp[st.top()] == s[i]) st.pop();
		else break;
	}
	return st.empty();
}
int main()
{
	string s;
	cin >> s;
	cout << ((isValid(s) == 1) ? "Valid" : "Invalid");
	return 0;
}