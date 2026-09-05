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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;

        int step = 1;

        while(step < lists.size()){
            for(int i = 0; i + step < lists.size(); i += (2*step)){
                lists[i] = merge2Lists(lists[i], lists[i + step]);
            }
            step *= 2;
        }
        return lists[0];
    }
    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* cur = &dummy;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                cur->next = list1;
                list1 = list1->next;
            }
            else{
                cur->next = list2;
                list2 = list2->next;
            }

            cur = cur->next;
        }
        if(list1) cur->next = list1;
        else if(list2) cur->next = list2;

        return dummy.next; 
    }
};
