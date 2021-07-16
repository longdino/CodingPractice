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
            if(head->child) {
                tnext = head->next ? head->next : NULL;
                lvl = flatten(head->child);
                if(!lvl) break;
                lvl->prev = head;
                ttail = lvl;
                while(ttail->next) {
                    ttail = ttail->next;
                }
                ttail->next = tnext;
                if(tnext) tnext->prev = ttail;
                head->next = lvl;
                head->child = NULL;
                if(ttail->next) head = ttail->next;
                continue;
            }
            if(!head->next) {
                while(head->prev) {
                    head = head->prev;
                }
                return head;
            }
            head = head->next;
        }
        return head;
    }
};