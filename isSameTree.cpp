#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool solve(TreeNode *p, TreeNode *q)
{
    if ((p && !q || !p && q) || p->val != q->val)
    {
        return false;
    }
    if (!p->left && !q->left && !p->right && !q->right && p->val == q->val)
    {
        return true;
    }
    bool l = solve(p->left, q->left);
    bool r = solve(p->right, q->right);

    return l && r;
}
bool isSameTree(TreeNode *p, TreeNode *q)
{
    return solve(p, q);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);

    TreeNode *root1 = new TreeNode(1);
    TreeNode *l1r1 = new TreeNode(2);
    TreeNode *r1l1 = new TreeNode(3);
    TreeNode *r1r2 = new TreeNode(7);

    root->left = l1;
    root->right = r1;

    root1->left = l1r1;
    root1->right = r1l1;

    cout << isSameTree(root, root1) << endl;

    //     1
    // 2       3
    //      6     7

    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete root1;
    delete r1;
    delete l1;
    delete root;
}