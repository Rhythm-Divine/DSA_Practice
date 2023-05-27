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

void deleteNode(ListNode *node)
{
    *node = *node->next;
    cout << node << endl;
    cout << (void *)node << endl;
}
int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    cout << l2 << endl;
    l1->next = l2;
    l2->next = l3;

    deleteNode(l2);
    while (l1 != NULL)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }
}