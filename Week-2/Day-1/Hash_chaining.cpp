/*

Definition :    Hashing with chaining

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
class HashChain
{
private:
    map<int, ListNode*>mp;          //Hash map which store key and linkedlist as a value
public:
    void setkey(int x, int y)
    {
        ListNode* newNode = new ListNode(y);
        if (mp.find(x) != mp.end())
        {
            ListNode* head = mp[x];
            while (head->next != NULL) head = head->next;
            head->next = newNode;
        }
        else mp[x] = newNode;
    }
    void print(int key)
    {
        ListNode *value = mp[key];
        if (!value)
        {
            cout << "There is no exist any key\n";
            return;
        }
        while (value)
        {
            cout << value->val << " ";
            value = value->next;
        }
        cout << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    HashChain h;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter key and value\n";
        int key, value;
        cin >> key >> value;
        h.setkey(key, value);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int key;
        cin >> key;
        h.print(key);
    }
}