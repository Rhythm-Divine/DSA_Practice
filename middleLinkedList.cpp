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

   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1=new ListNode(0);
        ListNode* head=l1;
        while(list2 && list1){
        if(list1->val<=list2->val){
            l1->next=new ListNode(list1->val);
            l1=l1->next;
            list1=list1->next;
        }else{
            l1->next=new ListNode(list2->val);
            l1=l1->next;
            list2=list2->next;
        }
        }
        while(list1){
             l1->next=new ListNode(list1->val);
            l1=l1->next;
            list1=list1->next;
        }
        while(list2){
            l1->next=new ListNode(list2->val);
            l1=l1->next;
            list2=list2->next;
        }
        return head->next;
    }
int main()
{
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(3);
    ListNode *l3=new ListNode(6);
    ListNode *l4=new ListNode(7);

    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=NULL;

     ListNode *x1=new ListNode(1);
    ListNode *x2=new ListNode(2);
    ListNode *x3=new ListNode(9);
    ListNode *x4=new ListNode(11);

    x1->next=x2;
    x2->next=x3;
    x3->next=x4;
    x4->next=NULL;

    ListNode* ans = mergeTwoLists(l1,x1);
    while(ans){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}