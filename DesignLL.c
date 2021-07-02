


typedef struct MyLinkedList {
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    list->val = -1;
    list->next = NULL;
    
    return list;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    while (i <= index) {
        //printf("value: %d\n", obj->val);
        if (obj->val == -1) return -1;
        else if (i == index) {
            //printf("Found value: %d\n", obj->val);
            return obj->val;
        }
        
        obj = obj->next;
        i++;
    }
    
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj->val == -1) {
        obj->val = val;
        //printf("new list: %d\n", obj->val);
        return;
    }
    struct MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = obj;
    
    obj->val= node->val;
    obj->next = node->next;
    //printf("new head: %d\n", obj->val);
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    while(obj->next) {
        obj = obj->next;
    }
    
    struct MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;
    
    obj->next = node;
        
    return;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    int i = 1;
    
    while(obj->next) {
        if (i == index) {
            struct MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            node->val = val;
            node->next = obj->next;
            obj->next = node;
            //printf("Added at index %d!\n", i);
            return;
        }
        i++;
        obj = obj->next;
    }
    printf("i = %d\n", i);
    if (i == index) {
        struct MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
        node->val = val;
        node->next = NULL;
        //printf("Added at the end!\n");
        obj->next = node;
    }
    
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i = 0;
    while(obj->next) {
        if (i == index) {
            //printf("original value: %d\n", obj->val);
            struct MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            node = obj->next;
            obj->val = node->val;
            obj->next = node->next;
            //printf("Removed! Now the value at %d is: %d\n", i, obj->val);
            return;
        }
        i++;
        obj = obj->next;
    }
    if (i == index) {
        obj->val = -1;
        obj->next = NULL;
    }
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/