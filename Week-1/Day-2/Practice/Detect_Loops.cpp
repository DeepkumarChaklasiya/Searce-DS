/*
Definition : Detect Loop in LinkedList
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

string detectLoop(ListNode* root)
{
	//I am using Floyd’s Cycle-Finding Algorithm
	ListNode *slow = root, *fast = root;
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return "Loop found";
		}
	}
	return "No Loop";
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
	/*Here I am adding loops in list for checking*/
	tmp->next = root->next;
	cout << detectLoop(root);
	return 0;
}