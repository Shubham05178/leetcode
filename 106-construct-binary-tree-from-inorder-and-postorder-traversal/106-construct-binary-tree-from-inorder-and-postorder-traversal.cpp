/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
* Author - Shubham Nagaria
* Date - 18th April 2022
Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* construct(vector<int>&postorder, int posstart, int posend, int instart, int inend, unordered_map<int,int>&mp){
        if(posstart>posend)
            return NULL;
        TreeNode* node = new TreeNode(postorder[posend]);
        int indx = mp[postorder[posend]]-instart;
        node->left = construct(postorder,posstart,posstart+indx-1,instart, mp[postorder[posend]]-1,mp);
        node->right = construct(postorder,posstart+indx,posend-1,mp[postorder[posend]]+1,inend,mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int n = inorder.size();
        for(int i = 0 ; i <n; i++)
            mp[inorder[i]]=i;
        return construct(postorder,0,n-1,0,n-1,mp);
    }
};