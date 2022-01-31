/*

Definition :    Merge k Sorted Lists

TestCase :

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* head = NULL;
        ListNode* tail = head;
        while (!pq.empty()) {
            auto temp = pq.top();
            auto tmp2 = temp;
            pq.pop();
            if (temp.second->next) pq.push({temp.second->next->val, temp.second->next});
            temp.second->next = NULL;
            if (head == NULL) {
                head = temp.second;
                tail = temp.second;
            }
            else {
                tail->next = temp.second;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        return head;
    }
};