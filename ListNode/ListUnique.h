#ifndef LISTUNIQUE_H
#define LISTUNIQUE_H

#include "ListNode.h"

/*
删除排序列表中重复的元素（保留一个）
*/

ListNode* ListUnique(ListNode* head){
    ListNode* p = head, *temp;
    while (p && p->next) {
        if(p->data == p->next->data){
            temp = p->next;
            p->next = p->next->next;
            delete temp;
        }else{
            p = p->next;
        }
    }
    return head;
}

#endif // LISTUNIQUE_H
