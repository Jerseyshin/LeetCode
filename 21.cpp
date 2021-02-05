#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//recursive
ListNode* mergeTwoLists_rcv(ListNode* l1, ListNode* l2){
    if(l1 == nullptr)
        return l2;
    else if(l2 == nullptr)
        return l1;
    else if(l1->val < l2->val){
        l1->next = mergeTwoLists_rcv(l1->next, l2);
        return l1;
    }else{
        l2->next = mergeTwoLists_rcv(l1, l2->next);
        return l2;
    }
}

//iteration
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* preHead = new ListNode(-1);
    ListNode* pre = preHead;
    while(l1 != nullptr && l2 != nullptr){
        if(l1->val < l2->val){
            pre->next = l1;
            l1 = l1->next;
        }else{
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }

    pre->next = (l1 == nullptr) ? l2 : l1;
    return preHead->next;
}

