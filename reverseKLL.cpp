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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
    {
        return head;
    }

    int count = 0;
    ListNode *curr = head;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    ListNode *before = nullptr;
    ListNode *after=nullptr;
    ListNode *currHead = nullptr;
    ListNode *currTail = head;
    curr = head;
    ListNode *updatedHead = nullptr;

    while (count >= k)
    {
        for (int i = 0; i < k; i++)
        {
            after = curr->next;
            curr->next = before;
            before = curr;
            curr = after;
        }


        if (!updatedHead)
        {
            updatedHead = before;
        }
        if (currHead)
        {
            currHead->next = before;
        }
        currTail->next = curr;

        currHead = currTail;
        currTail = curr;
        before = nullptr;
        count -= k;
    }
    return updatedHead;
}
int main()
{

    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = nullptr;

    ListNode *ans = reverseKGroup(l1, 3);

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    free(l1);
    free(l2);
    free(l3);
    free(l4);
    free(l5);
}