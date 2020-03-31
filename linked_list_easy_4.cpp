//一次性ac的快乐
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/771/
//虽然memory用的挺多

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = l1;
        ListNode* p = dummy ->next;
        ListNode* pre = dummy;
        ListNode* q = l2;
        while(q!=NULL){
            if(p!= NULL && p->val <= q->val){p = p->next; pre = pre->next;}
            else{
                ListNode* temp = new ListNode(q->val);
                temp->next = p;
                pre ->next = temp;
                pre = pre->next;
                q = q->next;
            }
        }
        return dummy->next;
    }
};
