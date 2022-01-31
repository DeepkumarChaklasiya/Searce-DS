/*

Definition :	Isomorphic Strings

Time complexity : O(n)

Space complexity : O(n)

Author : Deep Chaklasiya

*/


#include<bits/stdc++.h>
using namespace std;

bool isomorphic(string s1, string s2)
{
	int n = s1.length(), m = s2.length();
	/*	If length of both strings are not same then strings are not isomorphic	*/
	if (n != m)
	{
		return false;
	}
	/*	First map for assigning or mapping  char from first string to char from second string*/
	unordered_map<char, char>mp1, mp2;
	for (int i = 0; i < n; i++)
	{
		char first = s1[i], second = s2[i];
		if (mp1.find(first) != mp1.end())
		{
			//If the given char is alreay mapped with other character then false
			if (mp1[first] != second) return false;
		}
		else
		{
			if (mp2.find(second) != mp2.end())
			{
				return false;
			}
			//put both chars pair into map
			mp1[first] = second;
			mp2[second] = first;
		}
	}
	return true;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << isomorphic(s1, s2) << endl;
	return 0;
}