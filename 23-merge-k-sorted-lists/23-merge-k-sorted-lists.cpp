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
    ListNode* mergeTwoList(ListNode* list1 , ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                dummy->next = list1;
                list1 = list1->next;
                dummy = dummy->next;
            }
            else{
                dummy->next = list2;
                list2 = list2->next;
                dummy = dummy ->next;
            }
        }
        if(list1) dummy->next = list1;
        if(list2) dummy->next = list2;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0) return NULL;
        if(size ==1) return lists[0];
        int curr = 1;
        while(curr < size){
            for(int idx = 0; idx < size - curr; idx += (curr*2))
                lists[idx] = mergeTwoList(lists[idx],lists[idx + curr]);
            curr *= 2;
        }
        return lists[0];
    }
};