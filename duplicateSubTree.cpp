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

unordered_map<string, int> m;
vector<TreeNode *> v;
string s;
void postOrder(TreeNode *root)
{
    
    if (!root)
    {
        s += "N";
        return;
    }
    
    s.clear();
    postOrder(root->left);
    s += "N";
    postOrder(root->right);
    s += "N";
    s += to_string(root->val);
    
    if (m[s] == 1)
    {
        v.push_back(root);
    }
    m[s]++;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    m.clear();
    v.clear();

    postOrder(root);
    for (auto i : m)
    {
        cout << i.first << "->" << i.second << endl;
    }
    return v;
}
int main()
{
    TreeNode *root = new TreeNode(2);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *r1 = new TreeNode(2);
    TreeNode *l1l2 = new TreeNode(3);
    TreeNode *r1l2 = new TreeNode(3);
    root->left = l1;
    root->right = r1;
    l1->left = l1l2;
    r1->left = r1l2;
    vector<TreeNode*> ans= findDuplicateSubtrees(root);
    
}