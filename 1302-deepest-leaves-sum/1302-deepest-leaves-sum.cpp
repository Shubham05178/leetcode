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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>levelnodes;
        levelnodes.push(root);
        int sum, size;
        TreeNode *front;
        while(levelnodes.size()) {
            size = levelnodes.size();
            sum = 0;
            while(size--){
                front = levelnodes.front();
                levelnodes.pop();
                sum += front->val;
                if(front->left)
                    levelnodes.push(front->left);
                if(front->right)
                    levelnodes.push(front->right);
            }
        }
        return sum;
    }
};