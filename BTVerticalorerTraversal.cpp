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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // m[vertical][level]->{nodes}
    map<int, map<int, multiset<int>>> m;
    //{node,{vertical,level}}
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    vector<vector<int>> ans;

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front().first;
            auto data = q.front().first->val;
            int ver = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            m[ver][level].insert(data);
            if (node->left)
            {
                q.push({node->left, {ver - 1, level + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {ver + 1, level + 1}});
            }
        }
    }

    for (auto i : m)
    {
        vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                temp.push_back(k);
            }
        }
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
    //         1
    //     2        3
    // 4       5|6      7
    root->left = l1;
    root->right = r1;
    l1->left = l1l1;
    l1->right = l1r1;
    r1->left = r1l1;
    r1->right = r1r2;

    vector<vector<int>> v = verticalTraversal(root);
    cout << "Size : " << v.size() << endl;
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete l1l1;
    delete r1;
    delete l1;
    delete root;
}