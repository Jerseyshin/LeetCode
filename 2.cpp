#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode;
    ListNode* p = head;
    int c = 0;
    while(l1 != nullptr && l2 != nullptr){
        ListNode* q = new ListNode;
        q->val = l1->val + l2->val + c;
        c = q->val / 10;
        q->val = q->val % 10;
        p->next = q;
        p = q;
        l1 = l1->next;
        l2 = l2->next;
    }
    //cout<<"l1 l2 end"<<endl;
    ListNode* l = (l1 != nullptr) ? l1 : l2;

    for(; l != nullptr; l = l->next){
        ListNode* q = new ListNode;
        q->val = l->val + c;
        c = q->val / 10;
        q->val = q->val % 10;
        p->next = q;
        p = q;
    }
    //cout<<"end"<<endl;
    if(c != 0){
        ListNode* q = new ListNode;
        q->val = c;
        p->next = q;
        p = q;
    }

    return head->next;
}

int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* pre = l1;
    ListNode* p = new ListNode(4);
    pre->next = p;
    pre = pre->next;
    p = new ListNode(3);
    pre->next = p;
    pre = pre->next;

    ListNode* l2 = new ListNode(5);
    pre = l2;
    p = new ListNode(6);
    pre->next = p;
    pre = pre->next;
    p = new ListNode(4);
    pre->next = p;
    pre = pre->next;

    p = l1;
    while(p!=nullptr){
        cout<<p->val;
        p=p->next;
    }
    cout<<endl;
    p = l2;
    while(p!=nullptr){
        cout<<p->val;
        p=p->next;
    }
    cout<<endl;



    cout<<"finish input"<<endl;
    p = addTwoNumbers(l1, l2);
    cout<<"end p"<<endl;
    while(p!=nullptr){
        cout<<p->val;
        p=p->next;
    }
    return 0;
}