/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* lvl;
        Node* tnext;
        Node* tprev;
        Node* ttail;
        while(head) {
            printf("value: %d\n", head->val);
            
            if(head->child) {
                tnext = head->next;
                tprev = head->next ? head->next->prev: NULL;
                lvl = flatten(head->child);
                if(!lvl) break;
                lvl->prev = head;
                ttail = lvl;
                while(ttail->next) {
                    ttail = ttail->next;
                }
                ttail->next = tnext;
                tnext->prev = ttail;
                head->next = lvl;
            }
            
            head = head->next;
        }
        
        return head;
       
    }
};