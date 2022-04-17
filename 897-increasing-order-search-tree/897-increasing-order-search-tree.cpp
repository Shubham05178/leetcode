/**
* Leetcode Problem - https://leetcode.com/problems/increasing-order-search-tree/
* Author - Shubham Nagaria
* Date -17th April 2022
Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head= new TreeNode(0),* curr = root , *temp ,*helper;
        TreeNode* tail = head;
        while(curr){
            if(!curr->left){
                tail->right = curr;
                tail =curr;
                curr= curr->right;
            }
            else{
                temp = curr->left;
                while(temp->right != NULL)
                    temp= temp->right;
                temp->right = curr;
                helper= curr->left;
                curr->left=NULL;
                curr= helper;
                }
            }
        return head->right;
    }
};