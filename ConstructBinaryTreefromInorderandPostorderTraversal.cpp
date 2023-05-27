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
TreeNode *solve(int l, int r, int &pidx, unordered_map<int, int> &m, vector<int> &inorder, vector<int> &postorder)
{
    if (l > r)
        return nullptr;
    int idx = m[postorder[pidx]];
    TreeNode *root = new TreeNode(postorder[pidx]);
    pidx--;
    root->right = solve(idx + 1, r, pidx, m, inorder, postorder);
    root->left = solve(l, idx - 1, pidx, m, inorder, postorder);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
        return nullptr;
    unordered_map<int, int> m;
    int x = 0;
    for (auto i : inorder)
    {
        m[i] = x;
        x++;
    }
    int pidx = postorder.size() - 1;
    return solve(0, inorder.size() - 1, pidx, m, inorder, postorder);
}

void inorderT(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorderT(root->left);
    cout << root->val << " ";
    inorderT(root->right);
}
int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *ans = buildTree(inorder, postorder);
    inorderT(ans);
}