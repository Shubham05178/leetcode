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
    pair<bool, int> depth(TreeNode* node) {
        if(node == NULL) 
            return {true, 0};
        pair<bool, int> leftsubtree, rightsubtree;
        leftsubtree = depth(node -> left);
        rightsubtree = depth(node -> right);
        return {abs(leftsubtree.second - rightsubtree.second) <= 1 && leftsubtree.first && rightsubtree.first, max(leftsubtree.second, rightsubtree.second) + 1};
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) 
            return true; 
        return depth(root).first;
    }
};