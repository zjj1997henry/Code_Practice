#ifndef LISTNODE_H
#define LISTNODE_H

#include <vector>
#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;

    ListNode(){
        data = 0;
        next = nullptr;
    }

    ListNode(int d, ListNode *p):data(d), next(p){

    }
};

ListNode* mallocList(const vector<int> values){
    ListNode* temp, *head;
    head = new ListNode(0, nullptr);
    temp = head;
    for(auto i = values.begin(); i != values.end(); i++){
        ListNode* node = new ListNode(*i, nullptr);
        temp->next = node;
        temp = temp->next;
    }
    temp = head->next;
    delete head;
    return temp;
}

void freeList(ListNode** head){
    ListNode* p = *head, *temp;
    while (p) {
        temp = p->next;
        delete p;
        p = temp;
    }
    *head = nullptr;
}

void printList(const ListNode* head){
    const ListNode* p = head;
    while (p) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

#endif // LISTNODE_H
