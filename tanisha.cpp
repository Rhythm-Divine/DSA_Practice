    #include <bits/stdc++.h>
    using namespace std;
    
      struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
   vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        TreeNode* curr = root, *prev;
        
        while(curr)
        {
            if(curr->left == NULL)
            {
                result.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                prev = curr->left;
                
                while(prev->right)
                {
                    prev = prev->right;
                }
                
                prev->right = curr;
                
                TreeNode* temp = curr;
                
                curr = curr->left;
                
                temp->left = NULL;
            }
        
        }
        return result;
    }

    int main(){
    }
    