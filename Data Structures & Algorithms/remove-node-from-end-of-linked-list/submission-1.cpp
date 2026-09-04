/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy, *fast = dummy;
        
        for(int i = 0; i < n; ++i) fast = fast->next;

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};
//利用相距n的快慢指標
//當快指標為null就刪除慢指標的下一個點