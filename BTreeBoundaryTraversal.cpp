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

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    // vector<int> ans;
    // solve(root,ans);
    // return ans;
    vector<int> res;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        res.push_back(temp->val);
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->right != NULL)
                q.push(curr->right);
            if (curr->left != NULL)
                q.push(curr->left);
        }
    }
    return res;
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

    for (auto i : rightSideView(root))
    {
        cout << i << " ";
    }

    delete r1l1r1;
    delete r1l1l1;
    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete r1;
    delete l1;
    delete root;
}