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
    void reorderList(ListNode* head) {
        ListNode* mid = findMiddle(head);
        ListNode* head_second = mid->next;
        mid->next = NULL;
        head_second = reverse(head_second);
        
        ListNode* curr = head;
        while(head_second){
            ListNode* temp1 = curr->next;
            ListNode* temp2 = head_second->next;
            curr->next = head_second;
            head_second->next = temp1;
            curr = temp1;
            head_second = temp2;
        }                
    }
    ListNode* findMiddle(ListNode* head){
        if(!head) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(!head) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};
