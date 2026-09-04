/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        unordered_map<Node*, Node*> hash;
        hash.reserve(100);
        Node* newHead = new Node(head->val);

        Node* currN = newHead;
        Node* currO = head;
        hash[currO] = currN;
        while(currO->next){
            Node* temp = new Node(currO->next->val);
            currN->next = temp;
            hash[currO->next] = temp;

            currN = currN->next;
            currO = currO->next;
        }
        
        currN = newHead;
        currO = head;      
        while(currO){
            currN->random = hash[currO->random];

            currN = currN->next;
            currO = currO->next;
        }

        return newHead;
    }
};
