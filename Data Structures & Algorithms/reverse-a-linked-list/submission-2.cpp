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
    ListNode* reverseList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = NULL;

        while(fast != NULL){
            ListNode* temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
            cout<<1;
        }

        return slow;
    }
};
//0 1 2 3
//