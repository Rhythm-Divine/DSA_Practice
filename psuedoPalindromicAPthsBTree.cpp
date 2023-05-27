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

int isPalindrome(vector<vector<int>> &x)
{
    vector<int> v_pal;
    unordered_map<int, int> m;
    for (auto i : x)
    {
        for (auto j : i)
        {
            m[j]++;
        }
        int cntOdds = 0;
        unordered_map<int, int>::iterator itr = m.begin();
        for (itr; itr != m.end(); itr++)
        {
            if (itr->second % 2 != 0)
            {
                cntOdds++;
            }
            else
            {
                continue;
            }
        }
        m.clear();
        if (cntOdds <= 1)
        {
            v_pal.push_back(1);
        }
    }
    return v_pal.size();
}
void DFS(TreeNode *node, vector<int> &temp, vector<vector<int>> &x)
{
    // int count = 0;
    // if (node == nullptr)
    // {
    //     return;
    // }
    // temp.push_back(node->val);
    // if (node->left == NULL && node->right == NULL)
    // {
    //     x.push_back(temp);
    // }

    // DFS(node->left, temp, x);

    // DFS(node->right, temp, x);
    // temp.pop_back();


    
}

int pseudoPalindromicPaths(TreeNode *root)
{

    vector<int> temp;
    vector<vector<int>> x;
    DFS(root, temp, x);
    int pal_paths = isPalindrome(x);
    return pal_paths;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(1);

    int ans = pseudoPalindromicPaths(root);
    cout << ans << endl;
}