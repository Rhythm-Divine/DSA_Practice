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

TreeNode *solve(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
    {
        return nullptr;
    }
    if (root->val == p->val || root->val == q->val)
    {
        return root;
    }
    TreeNode *l = solve(root->left, p, q);
    TreeNode *r = solve(root->right, p, q);
    if (l && r)
    {
        return root;
    }else if(l){
        return l;
    }else if(r){
        return r;
    }

    return nullptr;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return solve(root, p, q);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    // TreeNode *l1l1 = new TreeNode(4);
    TreeNode *l1r1 = new TreeNode(5);
    TreeNode *r1l1 = new TreeNode(4);
    TreeNode *r1r2 = new TreeNode(10);
    TreeNode *r1l1l1 = new TreeNode(8);
    TreeNode *r1l1r1 = new TreeNode(6);
    root->left = l1;
    root->right = r1;
    l1->right = l1r1;
    r1->left = r1l1;
    r1->right = r1r2;
    r1l1->left = r1l1l1;
    r1l1->right = r1l1r1;

    //         1
    // 2               3
    //     5       4        10
    //         8       6
    cout << lowestCommonAncestor(root, r1l1r1, r1l1l1)->val << endl;

    delete r1l1r1;
    delete r1l1l1;
    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete r1;
    delete l1;
    delete root;
}