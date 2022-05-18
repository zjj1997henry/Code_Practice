#ifndef LISTTOTALUNIQUE_H
#define LISTTOTALUNIQUE_H

#include "ListNode.h"

/*
删除排序列表重复的元素，一个也不保留
*/

ListNode* ListTotalUnique(ListNode* head)
{
    ListNode *vhead = new ListNode(0, head), *p, *temp;
    p = vhead;
    while (p->next && p->next->next) {
        if(p->next->data == p->next->next->data){
            int val = p->next->data;
            while (p->next && p->next->data == val) {
                temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
        }else{
            p = p->next;
        }
    }
    temp = vhead->next;
    delete vhead;
    return temp;
}

#endif // LISTTOTALUNIQUE_H
