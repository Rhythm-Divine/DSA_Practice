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
    if (!root)
    {
        return {{}};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = true;
    vector<int> temp;
    while (!q.empty())
    {
        int sz = q.size();
        
        for (int i = 0; i < sz; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            temp.push_back(t->val);
            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        if (!flag)
        {
            reverse(temp.begin(), temp.end());
        }
        flag=!flag;
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
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

    for (auto i : zigzagLevelOrder(root))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }

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