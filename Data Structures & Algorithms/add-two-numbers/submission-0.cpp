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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int temp = 0;
        while(l1 || l2 || temp){
            int sum = 0;
            cur->next = new ListNode();
            cur = cur->next;

            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(temp) sum += 1;

            cur->val = sum % 10;
            temp = sum / 10;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
