//https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/

// 注意用到了以前的dummyHead的技巧
// 在第一个之前设置一个虚假的头节点解决很多头部的插入的问题

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1,* q = l2,*curr = dummyHead;
        int carry = 0;
        while(p!= NULL || q!= NULL){
            int x = (p != NULL) ? p->val:0;
            int y = (q != NULL) ? q->val:0;
            int sum = carry + x + y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(p!= NULL) p = p->next;
            if(q!= NULL) q = q->next;
        }
        if(carry > 0) curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};

// 对于空值的处理还是非常需要注意的
// x, y 多设置了两个变量很好的简化了很多程序
// 如果单独用p, q是否为NULL很容易造成错误判断，漏解，混乱
