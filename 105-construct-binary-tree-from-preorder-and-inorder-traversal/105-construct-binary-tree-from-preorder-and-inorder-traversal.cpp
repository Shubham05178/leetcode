/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
* Author - Shubham Nagaria
* Date - 18th April 2022
Construct Binary Tree from Preorder and Inorder Traversal
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend, unordered_map<int,int>&mp){
        if(prestart > preend)
            return NULL;
        TreeNode* node = new TreeNode(preorder[prestart]);
        int indx = mp[preorder[prestart]];
        int x = indx - instart;
        node->left = construct(preorder,inorder, prestart+1, prestart+x,instart,indx-1,mp);
        node->right = construct(preorder,inorder,prestart+x+1,preend, indx+1, inend,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            mp[inorder[i]]=i;
        return construct(preorder,inorder,0, n-1, 0,n-1,mp);
        
    }
};