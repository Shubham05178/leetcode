/**
* Leetcode Problem - https://leetcode.com/problems/copy-list-with-random-pointer/
* Author - Shubham Nagaria
* Date - 12th March 2022
Copy List with Random Pointer
**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* curr = head;
        while(curr){
            Node* p = new Node(curr->val);
            p->next =curr->next;
            curr->next = p;
            curr = p->next;
        }
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* head2 = head->next,*curr2 = head->next;
        curr = head;
        while(curr && curr2){
            curr->next = curr->next->next;
            curr = curr->next;
            if(curr){
            curr2->next = curr2->next->next;
            curr2 = curr2->next;
            }
        }
        return head2;
    }
};