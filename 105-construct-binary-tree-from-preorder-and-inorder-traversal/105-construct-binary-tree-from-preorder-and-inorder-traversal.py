# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def construct(self, ps,pe,ins,ine,preorder,inorder,mp):
        if ps>pe:
            return None
        node = TreeNode(preorder[ps])
        x= mp[preorder[ps]]-ins
        node.left =  self.construct(ps+1,ps+x,ins,ins+x-1,preorder,inorder,mp)
        node.right = self.construct(ps+x+1,pe,ins+x+1,ine,preorder,inorder,mp)
        return node
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        mp={}
        for i,j in enumerate(inorder):
            mp[j]=i
        n = len(preorder)-1
        return self.construct(0,n,0,n,preorder,inorder,mp)