/**
* Leetcode Problem - https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
* Author - Shubham Nagaria
* Date - 18th April 2022
Kth Smallest Element in a BST
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
    void traverse(TreeNode* root,int& k, int& val){
        if(root == NULL) return;
        traverse(root->left,k,val);
        k--;
        if(k==0)
            val = root->val;
        traverse(root->right,k,val);
    }
    int kthSmallest(TreeNode* root, int k) {
        int val;
        traverse(root,k,val);
        return val;
    }
};