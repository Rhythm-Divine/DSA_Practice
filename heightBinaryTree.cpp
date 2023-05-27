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
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int countL = maxDepth(root->left);
    int countR = maxDepth(root->right);
    cout << countL << " " << countR << endl;
    return max(countL, countR) + 1;
}
int main()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *l1 = new TreeNode(9);
    TreeNode *r1 = new TreeNode(20);
    TreeNode *r1l1 = new TreeNode(15);
    TreeNode *r1r2 = new TreeNode(7);

    root->left = l1;
    root->right = r1;
    r1->left = r1l1;
    r1->right = r1r2;

    int ans = maxDepth(root);
    cout << ans << endl;

   
    delete r1r2;
    delete r1l1;
    delete r1;
    delete l1;
    delete root;
}
// call to maxDepth(3):
//     countL = call to maxDepth(9) = 1
//     countR = call to maxDepth(20):
//         countL = call to maxDepth(15) = 1
//         countR = call to maxDepth(7) = 1
//     return max(countL, countR) + 1 = max(1, 1) + 1 = 2
// return max(countL, countR) + 1 = max(1, 2) + 1 = 3