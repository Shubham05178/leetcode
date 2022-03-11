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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        
        ListNode* curr=head;
        int count = 1;
        while(curr->next!=nullptr)
        {
            count++;
            curr=curr->next;
        }
        k=k%count;
        if(k==0)
            return head;
        
        count-=k;
        curr->next=head;
        curr=head;
        while(count>1){
            curr=curr->next;
            count--;   
        }
        head=curr->next;
        curr->next=nullptr;
        return head;
    }
};