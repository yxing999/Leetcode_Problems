/*
Judge if a tree is a valid BST.
When encountering a Tree Problem, we should try recursion firstly.

Set upper and lower limits, loop on every node recursively, following the definition of BST.
use long long to avoid overflow.

Time: O(n);
Space: O(1).
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
    }
    bool check(TreeNode* root, long long left, long long right){
        if(!root) return true;
        else return(root->val>left&&root->val<right)
            &&check(root->left,left,root->val)
            &&check(root->right,root->val,right);
    }
};

/*
Iterative traverse the tree.
return false when we meet non-ascending order.

Time: O(n);
Space O(n).
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> nodes;
        TreeNode *cur=root;
        while(!nodes.empty()||cur){
            while(cur){
                nodes.push(cur);
                cur=cur->left;
            }
            cur=nodes.top();nodes.pop();
            if(!values.empty()&&cur->val<=values.back()) return false;
            values.push_back(cur->val);
            cur=cur->right;
        }
        return true;
    }
};