#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr->next!= NULL)
    {
        curr = curr->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    head->next=prev;
    return head;
}
int main()
{
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(3);
    ListNode *l4=new ListNode(4);

    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=NULL;

    ListNode* ans = reverseList(l1);
    while(ans!=NULL){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}