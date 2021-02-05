#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//length first
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p = head;
    int sz = 0;
    while(p != nullptr){
        sz++;
        p = p->next;
    }
    int n_ad = sz + 1 - n;
    p = head;
    int k = 0;
    if(n_ad == 1){
        head = p->next;
        delete p;
    }else{
        while(p!=nullptr){
            k++;
            if(k == n_ad - 1){
                ListNode* q = p->next;
                p->next = q->next;
                delete q;
                break;
            }
            p = p->next;
        }
    }
    return head;
}

//stack
ListNode* removeNthFromEnd_stack(ListNode* head, int n){
    //Pre-process
    ListNode* first = new ListNode(0, head);
    stack<ListNode*> st;
    ListNode* p = first;
    while(p!=nullptr){
        st.push(p);
        p = p->next;
    }
    for(int i=0; i<n; i++){
        st.pop();
    }
    p = st.top();
    ListNode* del = p->next;
    p->next = del->next;
    delete del;
    ListNode* ans = first->next;
    delete first;
    return ans;
}

//double_pointer
ListNode* removeNthFromEnd_double_pointer(ListNode* head, int n){
    //pre-process
    ListNode* preHead = new ListNode(0, head);
    ListNode* first = preHead;
    ListNode* second = preHead;
    for(int i=0; i<=n; i++)
        first = first->next;
    while(first!=nullptr){
        first = first->next;
        second = second->next;
    }
    ListNode* del = second->next;
    second->next = del->next;
    delete del;
    ListNode* ans = preHead->next;
    delete preHead;
    return ans;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* p = new ListNode(2);
    ListNode* q = head;
    q->next = p;
    q = p;
    p = new ListNode(3);
    q->next = p;
    q = p;
    p = new ListNode(4);
    q->next = p;
    q = p;
    p = new ListNode(5);
    q->next = p;
    q = p;
    
    p = head;
    while(p!=nullptr){
        cout<<p->val<<"->";
        p = p->next;
    }

    head = removeNthFromEnd(head, 2);
    p = head;
    while(p!=nullptr){
        cout<<p->val<<"->";
        p = p->next;
    }
}