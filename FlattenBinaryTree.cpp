/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {

        if (root == NULL)
            return;
        dfs(root);
    }

    void dfs(TreeNode* root) {
        // base
        if (root == NULL)
            return;

        // recurse
        dfs(root->left);

        if (root->left != NULL) {
            TreeNode* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        dfs(root->right);
    }
};