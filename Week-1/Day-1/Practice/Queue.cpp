/*
Time complexity : O(n)
Space complexity : O(n)
Problem link:	"https://leetcode.com/problems/first-unique-character-in-a-string/"
Author : Deep Chaklasiya
*/

#include<bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {

	unordered_map<char, int> mp;
	queue<char> q;

	for (int itr = 0; itr < s.size(); itr++) {
		if (!mp[s[itr]]) {
			mp[s[itr]] = itr + 1;
			q.push(s[itr]);
		}
		else mp[s[itr]] = -1;
	}

	while (!q.empty()) {
		if (mp[q.front()] != -1) return mp[q.front()] - 1;
		q.pop();
	}
	return -1;
}
int main()
{
	string s;
	cin >> s;
	cout << firstUniqChar(s);
	return 0;
}