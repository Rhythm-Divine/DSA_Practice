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

    bool solve(TreeNode *root,int tar,int sum){
        if(!root){
            return false;
        }
        sum+=root->val;
        if(!root->left && !root->right){
            return sum==tar;
        }
        
        
        bool l=solve(root->left,tar,sum);
        bool r=solve(root->right,tar,sum);
        return l||r;
       
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
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

    cout << hasPathSum(root,11) << endl;

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