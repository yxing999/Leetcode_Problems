'''
Build the result 2D array based on the height of the tree.
Traverse the tree, update the array.
the y coordinates of children depend on h and current x.

Time: O(n),
Space: O(1).
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        
        def getheight(root):
            if root is None:
                return 0
            return max(getheight(root.left),getheight(root.right)) + 1
        
        h = getheight(root)
        w = 2 ** h - 1
        res = [[""] * w for i in range(h)]
        
        def recursion(root, x, y):
            if root is None:
                return
            res[x][y] = str(root.val)
            curw = 2 ** (h - 1 - x) - 1
            y1 = y - (curw // 2 + 1)
            y2 = y + (curw // 2 + 1)
            recursion(root.left, x + 1, y1)
            recursion(root.right, x + 1, y2)
        
        recursion(root, 0, w // 2)
        return res