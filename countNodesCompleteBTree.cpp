#include <bits/stdc++.h>
using namespace std;
int ans = 0;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int left(TreeNode *root)
{
    int h = 1;
    while (root->left)
    {
        h++;
        root = root->left;
    }
    return h;
}
int right(TreeNode *root)
{
    int h = 1;
    while (root->right)
    {
        h++;
        root = root->right;
    }
    return h;
}
int solve(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int lh = left(root);
    int rh = right(root);
    if (lh == rh)
    {
        return ((1 << rh) - 1);
    }
    else
    {
        ans = solve(root->left) + solve(root->right);
    }
    return ans;
}
int countNodes(TreeNode *root)
{
    return solve(root);
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
    //         1
    //     2        3
    // 4       5|6      7
    root->left = l1;
    root->right = r1;
    l1->left = l1l1;
    l1->right = l1r1;
    r1->left = r1l1;
    r1->right = r1r2;

    cout<<countNodes(root)<<endl;
    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete l1l1;
    delete r1;
    delete l1;
    delete root;
}