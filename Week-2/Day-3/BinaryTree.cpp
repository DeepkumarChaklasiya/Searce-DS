/*

Definition :Construct complete binary tree from array

*/


#include<bits/stdc++.h>
using namespace std;

/* each node has data, pointer to left child and a pointer to right child */
struct Node
{
    int data;
    Node* left, * right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* constructTree(int ar[], int start, int end)
{
    if (start <= end)
    {
        Node* root = new Node(ar[start]);
        root->left = constructTree(ar, 2 * start + 1, end);
        root->right = constructTree(ar, 2 * start + 2, end);
        return root;
    }
    return NULL;
}

void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    Node* root = constructTree(ar, 0, n - 1);
    cout << "Inorder traversal : \n";
    inOrder(root);
}