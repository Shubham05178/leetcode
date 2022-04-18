/**
* Leetcode Problem - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
* Author - Shubham Nagaria
* Date - 18th April 2022
Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* construct(vector<int>&preorder,int prestart,int preend, vector<int>&next){
        if(prestart > preend)
            return NULL;
        TreeNode *node = new TreeNode(preorder[prestart]);
        if(next[prestart]<=preend){
            node->left = construct(preorder, prestart+1,next[prestart]-1,next);
            node->right = construct(preorder,next[prestart],preend,next);
        }
        else
            node->left = construct(preorder,prestart+1,preend,next);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        stack<int>st;
        vector<int>nextGreater(n);
        for(int i = n-1 ; i >=0 ; i--){
            while(!st.empty() && preorder[st.top()]< preorder[i])
                st.pop();
            if(st.empty()) nextGreater[i]=n;
            else nextGreater[i]=st.top();
            st.push(i);
        }
        return construct(preorder,0,n-1,nextGreater);
    }
};