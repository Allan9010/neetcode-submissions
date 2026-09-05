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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;
        
        ListNode* kth = getKth(groupPrev, k);
        while(kth){
            ListNode* groupHead = groupPrev->next;
            groupPrev->next = reverseList(groupHead, k);

            groupPrev = groupHead;

            kth = getKth(groupPrev, k);
        }

        return dummy.next;
    }
    ListNode* getKth(ListNode* curr, int k){
        while(curr != nullptr && k > 0){
            curr = curr->next;
            --k;
        }
        return curr;
    }
    ListNode* reverseList(ListNode* groupHead, int k){
        ListNode* prev = nullptr;
        ListNode* curr = groupHead;
        int count = 0;
        while(count < k){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            ++count;
        }//curr指向下一個group
        groupHead->next = curr;

        return prev;
    }//返回反轉後的頭，反轉後的尾要在這邊就接上下一段
};
