#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList {
  int val;
  struct MyLinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList *myLinkedListCreate() {
  MyLinkedList *list = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  list->val = -1;
  list->next = NULL;

  return list;
}

/** Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList *obj, int index) {
  int i = 0;
  while (i <= index) {
    // printf("value: %d\n", obj->val);
    if (obj->val == -1)
      return -1;
    else if (i == index) {
      // printf("Found value: %d\n", obj->val);
      return obj->val;
    }

    obj = obj->next;
    i++;
  }

  return -1;
}

/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList *obj, int val) {
  if (obj->val == -1) {
    obj->val = val;
    // printf("new list: %d\n", obj->val);
    return;
  }
  if (obj->next == NULL)
    obj->next = myLinkedListCreate();
  int curr = obj->val;
  obj->val = val;
  myLinkedListAddAtHead(obj->next, curr);
  return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList *obj, int val) {
  while (obj->next) {
    obj = obj->next;
  }

  struct MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
  node->val = val;
  node->next = NULL;

  obj->next = node;

  return;
}

/** Add a node of value val before the index-th node in the linked list. If
 * index equals to the length of linked list, the node will be appended to the
 * end of linked list. If index is greater than the length, the node will not be
 * inserted. */
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val) {
  int i = 1;

  while (obj->next) {
    if (i == index) {
      struct MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
      node->val = val;
      node->next = obj->next;
      obj->next = node;
      // printf("Added at index %d!\n", i);
      return;
    }
    i++;
    obj = obj->next;
  }
  // printf("i = %d\n", i);
  if (i == index) {
    struct MyLinkedList *node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    node->val = val;
    node->next = NULL;
    // printf("Added at the end!\n");
    obj->next = node;
  }

  return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index) {
  int i = 0;
  struct MyLinkedList *prev = NULL;
  while (obj) {
    if (i == index) {
      // printf("original value: %d\n", obj->val);
      if (obj->next) {
        if (prev) {
          prev->next = obj->next;
        } else {
          struct MyLinkedList *temp =
              (MyLinkedList *)malloc(sizeof(MyLinkedList));
          temp = obj->next;
          obj->val = temp->val;
          obj->next = temp->next;
          return;
        }
        free(obj);
      } else {
        if (prev) {
          prev->next = NULL;
        }
        free(obj);
      }

      // printf("Removed! Now the value at %d is: %d\n", i, obj->val);
      return;
    }
    i++;
    prev = obj;
    obj = obj->next;
  }
  return;
}

void myLinkedListFree(MyLinkedList *obj) { return; }

void printLinkedList(MyLinkedList *obj) {
  while (obj) {
    printf("%d -> ", obj->val);
    obj = obj->next;
  }

  printf("\n");
  return;
}

int main() {
  MyLinkedList *list = myLinkedListCreate();

  myLinkedListAddAtHead(list, 1);
  printLinkedList(list);
  myLinkedListAddAtTail(list, 3);
  printLinkedList(list);
  myLinkedListAddAtIndex(list, 1, 2);
  printLinkedList(list);
  printf("I get %d at index 1\n", myLinkedListGet(list, 1));
  printLinkedList(list);
  myLinkedListDeleteAtIndex(list, 2);
  printLinkedList(list);
  printf("I get %d at index 1\n", myLinkedListGet(list, 1));
  printLinkedList(list);

  printf("=================================================\n");

  MyLinkedList *list2 = myLinkedListCreate();

  myLinkedListAddAtHead(list2, 7);
  printLinkedList(list2);
  myLinkedListAddAtHead(list2, 2);
  printLinkedList(list2);
  myLinkedListAddAtHead(list2, 1);
  printLinkedList(list2);
  myLinkedListAddAtIndex(list2, 3, 0);
  printLinkedList(list2);
  myLinkedListDeleteAtIndex(list2, 2);
  printLinkedList(list2);
  myLinkedListAddAtHead(list2, 6);
  printLinkedList(list2);
  myLinkedListAddAtTail(list2, 4);
  printLinkedList(list2);
  printf("I get %d at index 4\n", myLinkedListGet(list2, 4));
  printLinkedList(list2);
  myLinkedListAddAtHead(list2, 4);
  printLinkedList(list2);
  myLinkedListAddAtIndex(list2, 5, 0);
  printLinkedList(list2);
  myLinkedListAddAtHead(list2, 6);
  printLinkedList(list2);

  printf("=================================================\n");

  MyLinkedList *list3 = myLinkedListCreate();

  myLinkedListAddAtHead(list3, 1);
  printLinkedList(list3);
  myLinkedListAddAtTail(list3, 3);
  printLinkedList(list3);
  myLinkedListAddAtIndex(list3, 1, 2);
  printLinkedList(list3);
  printf("I get %d at index 1\n", myLinkedListGet(list3, 1));
  printLinkedList(list3);
  myLinkedListDeleteAtIndex(list3, 0);
  printLinkedList(list3);
  printf("I get %d at index 1\n", myLinkedListGet(list3, 0));
  printLinkedList(list3);
  return 0;
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