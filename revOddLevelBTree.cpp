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

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == nullptr)
    {
        return {};
    }
    vector<vector<int>> ans;
    q.push(root);
    vector<int> temp;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}

void solve(TreeNode *l, TreeNode *r, int level)
{
    if (!l && !r)
    {
        return;
    }

    if (level % 2 == 0)
    {
        int left = l->val;
        l->val = r->val;
        r->val = left;
    }
    solve(l->left, r->right, level + 1);
    solve(l->right, r->left, level + 1);
}
TreeNode *reverseOddLevels(TreeNode *root)
{
    solve(root->left, root->right, 0);
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(0);
    TreeNode *l1 = new TreeNode(1);
    TreeNode *r1 = new TreeNode(2);
    TreeNode *l1l1 = new TreeNode(0);
    TreeNode *l1r1 = new TreeNode(0);
    TreeNode *l1l2 = new TreeNode(1);
    TreeNode *l1r2 = new TreeNode(1);
    TreeNode *r1l1 = new TreeNode(0);
    TreeNode *r1r1 = new TreeNode(0);
    TreeNode *r1l2 = new TreeNode(1);
    TreeNode *r1r2 = new TreeNode(1);
    TreeNode *r1l3 = new TreeNode(2);
    TreeNode *r1r3 = new TreeNode(2);
    TreeNode *r1l4 = new TreeNode(2);
    TreeNode *r1r4 = new TreeNode(2);

    root->left = l1;
    root->right = r1;
    l1->left = l1l1;
    l1->right = l1r1;
    l1l1->left = l1l2;
    l1l1->right = l1r2;
    l1r1->left = r1l2;
    l1r1->right = r1r2;
    r1->left = r1l1;
    r1->right = r1r1;
    r1l1->left = r1l4;
    r1l1->right = r1r4;
    r1r1->left = r1l3;
    r1r1->right = r1r3;

    vector<vector<int>> v = levelOrder(root);
    cout << "Size : " << v.size() << endl;
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    v.clear();
    v = levelOrder(reverseOddLevels(root));
    cout << "Size : " << v.size() << endl;
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    delete r1r4;
    delete r1l4;
    delete r1r3;
    delete r1l3;
    delete r1r2;
    delete r1l2;
    delete r1r1;
    delete r1l1;
    delete l1r2;
    delete l1l2;
    delete l1r1;
    delete l1l1;
    delete r1;
    delete l1;
    delete root;

    return 0;
}
