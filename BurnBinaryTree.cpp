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

TreeNode* node=nullptr;
    bool findNode(TreeNode* root,int data){
        if(!root){
            return false;
        }
        if(root->val==data){
            node=root;
            return true;
        }
        return (findNode(root->left,data) || findNode(root->right,data));
    }

    void makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m){
        if(!root){
            return;
        }
        if(root->left){
            m[root->left]=root;
        }
        if(root->right){
            m[root->right]=root;
        }
        makeParent(root->left,m);
        makeParent(root->right,m);
    }
    int amountOfTime(TreeNode* root, int start) {
        findNode(root,start);
        unordered_map<TreeNode*,TreeNode*> m;
        makeParent(root,m);
        cout<<endl;
        queue<TreeNode*> q;
        q.push(node);
        unordered_set<int> s;
        s.insert(node->val);
        
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            count++;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                if(curr->left && s.count(curr->left->val)==0){
                    q.push(curr->left);
                    s.insert(curr->left->val);
                }
                if(curr->right && s.count(curr->right->val)==0){
                    q.push(curr->right);
                    s.insert(curr->right->val);
                }
                if(m[curr] && s.count(m[curr]->val)==0){
                    q.push(m[curr]);
                    s.insert(m[curr]->val);
                }
            }
        }
        return count;
    }

    int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l1 = new TreeNode(5);
    TreeNode *r1 = new TreeNode(3);
    //TreeNode *l1l1 = new TreeNode(4);
    TreeNode *l1r1 = new TreeNode(4);
    TreeNode *l1r1l1 = new TreeNode(9);
    TreeNode *l1r1r1 = new TreeNode(2);
    TreeNode *r1l1 = new TreeNode(10);
    TreeNode *r1r2 = new TreeNode(6);
    //         1
    //     2        3
    // 4       5|6      7
    root->left = l1;
    root->right = r1;
    l1->right = l1r1;
    l1r1->left=l1r1l1;
    l1r1->right=l1r1r1;
    r1->left = r1l1;
    r1->right = r1r2;
    cout<<amountOfTime(root,3);
    
    delete r1r2;
    delete r1l1;
    delete l1r1r1;
    delete l1r1l1;
    delete l1r1;
    //delete l1l1;
    delete r1;
    delete l1;
    delete root;
}