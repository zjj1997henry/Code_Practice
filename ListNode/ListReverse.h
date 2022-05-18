#ifndef LISTREVERSE_H
#define LISTREVERSE_H

#include "ListNode.h"

/*
翻转链表
*/
ListNode* ListReverse(ListNode* p){
    ListNode *vhead = new ListNode(), *temp;
    while (p) {
        temp = p->next;
        p->next = vhead->next;
        vhead->next = p;
        p = temp;
    }
    temp = vhead->next;
    delete vhead;
    return temp;
}

#endif // LISTREVERSE_H
