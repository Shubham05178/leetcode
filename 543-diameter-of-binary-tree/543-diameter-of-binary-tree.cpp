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
    int maxi = 0;
    int diameter(TreeNode* root){
        if(root == NULL) return 0;
        int l = diameter(root->left);
        int r = diameter(root->right);
        maxi = max(maxi, l + r);
        return max(l,r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return maxi;
    }
};