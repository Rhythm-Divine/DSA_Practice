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

int solve(TreeNode *root, int ans, int sum)
{
    if(!root){
        return 0;
    }
    if (!root->left && !root->right)
    {
        sum *= 10;
        sum += root->val;
       
        return sum;
    }
    sum *= 10;
    sum += root->val;
    ans+=solve(root->left, ans, sum);
    ans+=solve(root->right, ans, sum);
    return ans;
}
int sumNumbers(TreeNode *root)
{
    int ans = 0;
    int sum = 0;
    return solve(root, ans, sum);
   
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(5);
    TreeNode *r1 = new TreeNode(1);
    TreeNode *r2 = new TreeNode(6);

    root->left = l1;
    root->right = r1;
    r1->right=r2;

    cout << sumNumbers(root) << endl;
}