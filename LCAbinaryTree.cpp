#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *leftS = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightS = lowestCommonAncestor(root->right, p, q);

    if (leftS == NULL)
    {
        return rightS;
    }
    else if (rightS == NULL)
    {
        return leftS;
    }
    else
    {
        return root;
    }
}
int main()
{
    TreeNode* n3;
    n3->val = 3;
    TreeNode *n5;
    n5->val = 5;
    TreeNode *n1;
    n1->val = 1;
    TreeNode *n6;
    n6->val = 6;
    TreeNode *n2;
    n2->val = 2;
    TreeNode *n0;
    n0->val = 0;
    TreeNode *n8;
    n8->val = 8;
    TreeNode *n7;
    n7->val = 7;
    TreeNode *n4;
    n4->val = 4;

    n3->left = n5;
    n3->right = n1;
    n5->left = n6;
    n5->right = n2;
    n1->left = n0;
    n1->right = n8;
    n6->left = NULL;
    n6->right = NULL;
    n0->left = NULL;
    n0->right = NULL;
    n8->left = NULL;
    n8->right = NULL;
    n2->left = n7;
    n2->right = n4;

    TreeNode *ans = lowestCommonAncestor(n3, n6, n4);
    cout << ans->val << endl;
}