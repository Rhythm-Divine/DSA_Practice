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

vector<vector<int>> getTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return {{}, {}, {}};
    }
    vector<int> inorder;
    vector<int> postorder;
    vector<int> preorder;
    vector<vector<int>> ans;
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        TreeNode *curr = it.first;
        int num = it.second;

        if (num == 1)
        {
            it.second = num + 1;
            preorder.push_back(it.first->val);
            st.push(it);
            if (curr->left)
            {
                st.push({curr->left, 1});
            }
        }
        else if (num == 2)
        {
            it.second = num + 1;
            inorder.push_back(it.first->val);
            st.push(it);
            if (curr->right)
            {
                st.push({curr->right, 1});
            }
        }
        else
        {
            postorder.push_back(it.first->val);
        }
    }
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);
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

    vector<vector<int>> v = getTraversal(root);
    cout<<"Size : "<<v.size()<<endl;
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