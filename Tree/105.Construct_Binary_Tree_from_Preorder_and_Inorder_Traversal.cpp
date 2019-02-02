/*
when encountering tree problem, recursion is always the first attempt.
The key point of this problem is:
locate the root value, find left tree part and right part based on root value.
The first element in preorder is root value, 
then we find this value in inorder, elements on the left is left part, right is right part.
left part and right part have the same length in preorder and inorder,
so we can find the left part and right part in preorder based on length.
Do this process recursively.

Time: O(n),
Space: O(1).
*/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode *root=help(preorder,inorder,0,0,n);
        return root;
    }
    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int pstart,int istart,int len){
        if(len<=0) return NULL;
        int rootval=preorder[pstart];
        TreeNode *root=new TreeNode(rootval);
        int ipos=istart;
        while(inorder[ipos]!=rootval) ipos++;
        int leftlen=ipos-istart,rightlen=len-leftlen-1;
        root->left=help(preorder,inorder,pstart+1,istart,leftlen);
        root->right=help(preorder,inorder,pstart+1+leftlen,ipos+1,rightlen);
        return root;
    }
};