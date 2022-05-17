# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        if original == target:
            return cloned
        if original.left:
            x = self.getTargetCopy(original.left, cloned.left, target)
            if x is not None:
                return x
        if original.right:
            y = self.getTargetCopy(original.right, cloned.right, target)
            if y is not None:
                return y