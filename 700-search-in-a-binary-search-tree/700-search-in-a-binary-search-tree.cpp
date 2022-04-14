/**
* Leetcode Problem - https://leetcode.com/problems/search-in-a-binary-search-tree/
* Author - Shubham Nagaria
* Date - 14th April 2022
Search in a Binary Search Tree
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
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root)   
        return nullptr;
    if(root->val < val)
       return searchBST(root->right,val);
    if(root->val > val)
       return searchBST(root->left,val);
    if(root->val == val)
        return root;
    return nullptr;
    }
};