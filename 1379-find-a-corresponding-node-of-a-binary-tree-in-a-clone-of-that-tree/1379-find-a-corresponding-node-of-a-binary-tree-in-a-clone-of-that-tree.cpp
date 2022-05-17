/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target )
            return cloned;
        if(original->left){
            TreeNode * c= getTargetCopy(original->left, cloned ->left,target);
            if(c!= NULL){
                return c;
            }
        }
        if(original->right){
           TreeNode*c=  getTargetCopy(original->right, cloned->right, target);
            if(c!=NULL)
                return c;
        }
        return NULL;
    }
};