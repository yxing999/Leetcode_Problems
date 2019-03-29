// Recursive
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *cur;
    void flatten(TreeNode* root) {
        if (!root) return;

        cur = root;
        flatten(root->left);

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        cur->right = temp;
        
        flatten(temp);
    }
};