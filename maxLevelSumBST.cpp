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

int maxLevelSum(TreeNode *root)
{
    int mx = INT_MIN;
    queue<TreeNode *> q;
    q.push(root);
    long long int curr = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            curr += node->val;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        mx = max<long long int>(curr, mx);
        curr = 0;
    }
    return mx;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(7);
    TreeNode *r1 = new TreeNode(0);
    TreeNode *r1l2 = new TreeNode(7);
    TreeNode *r1r2 = new TreeNode(-8);
    root->left = l1;
    root->right = r1;
    r1->left = r1l2;
    r1->right = r1r2;
   cout<<maxLevelSum(root)<<endl;
    delete (r1r2);
    delete (r1l2);
    delete (r1);
    delete (l1);
    delete (root);
}