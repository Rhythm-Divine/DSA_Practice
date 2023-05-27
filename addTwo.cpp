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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *temp = new ListNode(0);
  ListNode *head = temp;
  int carry = 0;

  int digit = 0;
  while (l1 != NULL || l2 != NULL || carry != 0)
  {
    int sum = 0;
    if (l1)
    {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2)
    {
      sum += l2->val;
      l2 = l2->next;
    }
    sum+=carry;
    digit = sum % 10;
    carry = sum / 10;
   
    head->next = new ListNode(digit);
    head = head->next;
  }
  return temp->next;
}
int main()
{

  ListNode *x1 = new ListNode(9);
  ListNode *x2 = new ListNode(9);
  x1->next = x2;
  ListNode *x3 = new ListNode(9);
  x2->next = x3;
  ListNode *x4 = new ListNode(9);
  x3->next = x4;
  ListNode *x5 = new ListNode(9);
  x4->next = x5;
  ListNode *x6 = new ListNode(9);
  x5->next = x6;
  ListNode *x7 = new ListNode(9);
  x6->next = x7;

  x7->next = NULL;

  ListNode *l1 = x1;

  ListNode *y1 = new ListNode(9);
  ListNode *y2 = new ListNode(9);
  y1->next = y2;
  ListNode *y3 = new ListNode(9);
  y2->next = y3;
  ListNode *y4 = new ListNode(9);
  y3->next = y4;
  y4->next = NULL;

  ListNode *l2 = y1;

  ListNode *temp = addTwoNumbers(l1, l2);
  for (int i = 0; i < 8; i++)
  {
    cout << temp->val << "->";
    temp = temp->next;
  }
}