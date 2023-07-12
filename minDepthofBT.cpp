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

int minDepth(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 1;
    }
    int l, r;
    l = r = INT_MAX;
    if (root->left)
    {
        l = minDepth(root->left);
    }
    if (root->right)
    {
        r = minDepth(root->right);
    }

    return min(l, r) + 1;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(3);
    TreeNode *l1l1 = new TreeNode(4);
    TreeNode *l1r1 = new TreeNode(5);
    TreeNode *r1l1 = new TreeNode(6);
    TreeNode *r1r2 = new TreeNode(7);

    root->left = l1;
    root->right = r1;
    r1->left = r1l1;
    r1->right = r1r2;

    cout << minDepth(root) << endl;

    //     1
    // 2       3
    //      6     7

    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete l1l1;
    delete r1;
    delete l1;
    delete root;
}
