/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

bool isPalindrome(struct ListNode* head){
    int i = 0;
    struct ListNode* temp = head;
    
    while(temp) {
        temp = temp->next;
        i++;
    }
    
    temp = head;
    //printf("length of the linked list: %d\n", i);
    int length = i % 2 == 0 ? i/2 : i/2 + 1;
    while(temp) {
        if(i == length) {
            temp = reverseList(temp);
            //printf("value at %d: %d\n", i, temp->val);
            break;
        }
        i--;
        temp = temp->next;
    }
    
    while(temp) {
        if(temp->val == head->val) {
            temp = temp->next;
            head = head->next;
        }
        else {
            return false;
        }
    }
    
    return true;
}