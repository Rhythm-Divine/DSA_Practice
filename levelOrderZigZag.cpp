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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool right = true;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp;
        TreeNode *node = q.front();
        q.pop();
        for (int i = 0; i < sz; i++)
        {
            if (right)
            {
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                temp.push_back(node->val);
            }
            else
            {
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }

                temp.push_back(node->val);
            }
            ans.push_back(temp);
            right = !right;
        }
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *l1 = new TreeNode(9);
    TreeNode *r1 = new TreeNode(20);
    TreeNode *r1l2 = new TreeNode(15);
    TreeNode *r1r2 = new TreeNode(7);
    root->left = l1;
    root->right = r1;
    r1->left = r1l2;
    r1->right = r1r2;
    vector<vector<int>> a = zigzagLevelOrder(root);
    for (auto i : a)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
    delete (r1r2);
    delete (r1l2);
    delete (r1);
    delete (l1);
    delete (root);
}