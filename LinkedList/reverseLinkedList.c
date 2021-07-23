/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Recursive method

struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !(head->next)) return head;
    struct ListNode* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

// Iterative method
/*
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    
    while(curr) {
        next = curr->next; 
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
*/