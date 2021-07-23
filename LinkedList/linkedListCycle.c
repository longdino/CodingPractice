/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *temp = head;
    bool ret = false;
    while(head) {
        if (abs(head->val) > 1000000) {
            ret = true;
            break;
        } 
        if (head->val < 0) head->val -= 1000000;
        else head->val += 1000000;
        head = head->next;
    }
    head = temp;
    while(head) {
        //printf("value: %d\n", head->val);
        if (abs(head->val) < 100000) break;
        if (head->val < 0) head->val += 1000000;
        else head->val -= 1000000;
        head = head->next;
    }
    return ret;
}