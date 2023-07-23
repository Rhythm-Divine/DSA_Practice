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
    ListNode *prev = nullptr;
    ListNode *temp = head;
    while (head->next)
    {
        temp = temp->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    head->next = prev;
    return head;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *rev1 = reverseList(l1);
    ListNode *rev2 = reverseList(l2);

    ListNode *ans = new ListNode();
    ListNode *curr = ans;
    int carry = 0;
    int sum = 0;
    int digit = 0;
    while (rev1 || rev2 || carry != 0)
    {
        if (rev1)
        {
            sum += rev1->val;
            rev1 = rev1->next;
        }
        if (rev2)
        {
            sum += rev2->val;
            rev2 = rev2->next;
        }
        sum += carry;
        digit = sum % 10;
        carry = sum / 10;
        sum = 0;
        curr->next = new ListNode(digit);
        curr = curr->next;
    }
    return reverseList(ans->next);
}

void deallocateList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main()
{
    ListNode *x1 = new ListNode(7);
    ListNode *x2 = new ListNode(2);
    x1->next = x2;
    ListNode *x3 = new ListNode(4);
    x2->next = x3;
    ListNode *x4 = new ListNode(3);
    x3->next = x4;
    // ListNode *x5 = new ListNode(9);
    // x4->next = x5;
    // ListNode *x6 = new ListNode(9);
    // x5->next = x6;
    // ListNode *x7 = new ListNode(9);
    // x6->next = x7;

    // x7->next = NULL;

    ListNode *l1 = x1;

    ListNode *y1 = new ListNode(5);
    ListNode *y2 = new ListNode(6);
    y1->next = y2;
    ListNode *y3 = new ListNode(4);
    y2->next = y3;
    // ListNode *y4 = new ListNode(9);
    // y3->next = y4;
    // y4->next = NULL;

    ListNode *l2 = y1;

    ListNode *temp = addTwoNumbers(l1, l2);
    for (int i = 0; i < 8; i++)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }

    // Deallocate memory for l1
    deallocateList(l1);

    // Deallocate memory for l2
    deallocateList(l2);

    deallocateList(temp);
}