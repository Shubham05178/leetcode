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
    void InTraversal(TreeNode* node, vector<int> &res) {
        if (node == NULL)
            return;
        InTraversal(node->left, res);
        res.push_back(node->val);
        InTraversal(node->right, res);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res1, res2, res;
        InTraversal(root1, res1);
        InTraversal(root2, res2);
        int s1 = res1.size(), s2 = res2.size(), ptr1 = 0, ptr2 = 0;
        while(ptr1 < s1 && ptr2 < s2) {
            if(res1[ptr1] < res2[ptr2])
                res.push_back(res1[ptr1++]);
            else
                res.push_back(res2[ptr2++]);
        }
        while(ptr1 < s1) res.push_back(res1[ptr1++]);
        while(ptr2 < s2) res.push_back(res2[ptr2++]);
        return res;
    }
};