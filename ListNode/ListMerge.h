#ifndef LISTMERGE_H
#define LISTMERGE_H

#include "ListNode.h"

/*
合并有序链表(升序)
*/

ListNode* ListMerge(ListNode* h1, ListNode* h2){
    ListNode* head = new ListNode(), *p = head;

    while (h1 && h2) {
        if(h1->data < h2->data){
            p->next = h1;
            p = p->next;
            h1 = h1->next;
        }else{
            p->next = h2;
            p = p->next;
            h2 = h2->next;
        }
    }

    if (h1) {
        p->next = h1;
    }

    if (h2) {
        p->next = h2;
    }

    p = head->next;
    delete head;
    return p;
}

ListNode * ListMerge2(ListNode* h1, ListNode * h2){
    if(!h1 && !h2) return nullptr;
    if(h1 && !h2) return h1;
    if(!h1 && h2) return h2;

    ListNode* p;
    if(h1->data < h2->data){
        p = h1;
        p->next = ListMerge2(h1->next, h2);
    }else{
        p = h2;
        p->next = ListMerge2(h1, h2->next);
    }
    return p;
}

#endif // LISTMERGE_H






