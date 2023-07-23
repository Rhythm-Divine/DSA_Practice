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
bool solve(TreeNode* root,int tar,vector<int> &ans){
    if(!root){
        return false;
    }
    ans.push_back(root->val);
    if(root->val==tar){
        return true;
    }
    if(root->left){
        if(solve(root->left,tar,ans)){
            return true;
        }  
    }
    if(root->right){
        if(solve(root->right,tar,ans)){
            return true;
        }
    }
     ans.pop_back();
    return false;
}
vector<int> printPath(TreeNode *root,int target){
    if(!root){
        return {};
    }
    vector<int> ans;
    solve(root,target,ans);
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
    for (auto i : printPath(root,4))
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