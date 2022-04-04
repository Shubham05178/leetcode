/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
* Leetcode Problem - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
* Author - Shubham Nagaria
* Date - 4th April 2022
Swapping Nodes in a Linked List
**/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*  curr, *first= head, *second = head;
        int i = 1;
        while(i<k){
            first = first->next;
            i++;
        }
        curr= first;
        while(curr->next){
            second = second->next;
            curr = curr->next;
        }
        int temp = second->val;
        second->val = first->val;
        first->val = temp;
        return head;
    }
};