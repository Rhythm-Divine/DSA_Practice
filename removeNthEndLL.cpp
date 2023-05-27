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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *before = head;
    ListNode *curr = head;
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
        if (count > n + 1)
        {
            before = before->next;
        }
    }
    if (count == n)
    {
        if (curr->next)
        {
            return curr->next;
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        head = before;
        before->next = before->next->next;
        return curr;
    }
}

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = NULL;

    ListNode *ans = removeNthFromEnd(l1, 2);
    while (ans != NULL)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
}