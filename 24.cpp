#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* swapPairs(ListNode* head) {
    if(head == nullptr)
        return head;
    ListNode* preHead = new ListNode(-1, head);
    ListNode* l1 = head;
    ListNode* l2 = head->next;
    ListNode* pre = preHead;
    while(l1 != nullptr && l2 != nullptr) {
        pre->next = l2;
        pre = l2->next;
        l2->next = l1;
        l1->next = pre;
        pre = l1;
        l1 = pre->next;
        l2 = (l1 == nullptr) ? nullptr : l1->next;
    }
    return preHead->next;
}

int main(){
    ListNode* head = new ListNode(1);
    /*ListNode* p = new ListNode(2);
    ListNode* q = head;
    q->next = p;
    q = p;
    p = new ListNode(3);
    q->next = p;
    q = p;
    p = new ListNode(4);
    q->next = p;
    q = p;*/
    head = swapPairs(head);
    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}