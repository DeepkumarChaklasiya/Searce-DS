/*
Definition : find middle element in LinkedList
			 If length is even then return (n/2)th node
			 If length is odd then return (n/2)+1 th node
Time complexity : O(n)
Space complexity : O(1)
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

int middleElement(ListNode* root)
{
	//using fast - slow pointer method
	ListNode *slow = root, *fast = root;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->val;
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
	cout << middleElement(root);
	return 0;
}