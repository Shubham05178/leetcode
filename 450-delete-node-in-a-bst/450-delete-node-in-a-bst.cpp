/**
* Leetcode Problem - https://leetcode.com/problems/delete-node-in-a-bst/submissions/
* Author - Shubham Nagaria
* Date - 18th April 2022
Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key)
            root->left= deleteNode(root->left,key);
        else if(root->val < key)
             root->right=deleteNode(root->right,key);
        else{
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;
            else{
                TreeNode* temp = root->left;
                while(temp->right)
                    temp= temp->right;
                root->val = temp->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
};