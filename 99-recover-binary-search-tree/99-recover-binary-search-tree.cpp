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
    TreeNode* second, *first , * prev;
    void findSwap(TreeNode * root){
        if(root == NULL) return;
        findSwap(root->left);
        if( prev != NULL && prev->val > root->val ){
            if(first == NULL) first = prev;
            second = root;
        }
        prev = root;
        findSwap(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL) return;
        second = NULL;
        first = NULL;
        prev = NULL;
        findSwap(root);
        if(first && second){
        int d = first->val;
        first->val = second->val;
        second->val = d;
        }
    }
};