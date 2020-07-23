// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3396/
// 都是写list的时候的几个常见的坑
// remove linked list elements

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode * p = dummy;
        while(p!= NULL && p->next != NULL){
            if(p->next->val == val){
                ListNode * temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else p = p->next;
        }
        return dummy->next;
    }
};