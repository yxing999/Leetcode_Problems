# Iterate

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root :
            return
        
        p = root
        while p :
            if p.left :
                temp = p.right
                p.right = p.left
                p.left = None
                
                maxleft = p
                while maxleft.right :
                    maxleft = maxleft.right
                maxleft.right = temp
                
            p = p.right