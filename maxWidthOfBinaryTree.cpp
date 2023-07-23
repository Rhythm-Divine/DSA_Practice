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
int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, long long int>> q;
    q.push({root, 1});
    long long int ans = 0;

    while (!q.empty())
    {
        long long int fidx = q.front().second;
        long long int sz= q.size();
        long long int lidx = q.size();
        
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front().first;
            long long int curridx = q.front().second;
            q.pop();
            if (node->left)
            {
                q.push({node->left, 2 * curridx - fidx});
            }
            if (node->right)
            {
                q.push({node->right, 2 * curridx + 1 - fidx});
            }
        }
        ans=max<long long int>(ans,lidx-fidx+1);
    }
    return ans;
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

    //         1
    // 2               3
    //     5       4        10
    //         8       6
    cout << widthOfBinaryTree(root) << endl;

    delete r1l1r1;
    delete r1l1l1;
    delete r1r2;
    delete r1l1;
    delete l1r1;
    delete r1;
    delete l1;
    delete root;
}