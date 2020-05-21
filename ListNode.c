/*链表*/
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}listnode;

listnode* initlist(listnode* head, int *data, int num){
    head = (listnode*)malloc(sizeof(listnode));
    listnode* first = (listnode*)malloc(sizeof(listnode));
    first->val = data[0];
    first->next = NULL;
    head->next = first;
    listnode* p = first;
    for(int i=1; i<num; i++){
        listnode* newnode = (listnode*)malloc(sizeof(listnode));
        newnode->val = data[i];
        p->next = newnode;
        p = p->next;
    }
    return head;
}

pirnt_list(listnode* head){
    listnode* p = head->next;
    while (p != NULL)
    {
        printf("元素为%d \n", p->val);
        p = p->next;
    }
}

