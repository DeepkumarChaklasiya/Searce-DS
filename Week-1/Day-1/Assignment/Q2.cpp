/*
Definition : Print the data of linked list
Time complexity : O(n)
Space complexity : O(n)
Author : Deep Chaklasiya
*/


#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x)
	{
		val = x;
		next = NULL;
	}
	/*
	Create a structure of our list which consist 2 parts.
		1. value of the node
		2. reference of the next node
	*/
};

void printList(ListNode* root)
{
	/*
	Starting from head or root of list and traverse until we found NULL node.
	*/
	while (root)
	{
		cout << root->val << " ";
		root = root->next;
	}
}

int main()
{
	int n;
	cin >> n;
	ListNode* root = NULL, *tmp = NULL;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (!tmp)
		{
			tmp = new ListNode(x);
			root = tmp;
		}
		else
		{
			tmp->next = new ListNode(x);
			tmp = tmp->next;
		}
	}
	printList(root);
	return 0;
}