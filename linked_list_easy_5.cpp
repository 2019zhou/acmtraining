//https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/772/

// 用快慢指针判断回文串
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = NULL;
        while(true){
            if(!fast->next){
                fast = slow->next;
                slow->next = prev;
                break;
            }else if(!fast->next->next){
                fast = slow->next->next;
                slow->next = prev;
                break;
            }else{
                fast = fast->next->next;
                ListNode* temp = slow->next;
                slow->next = prev;
                prev = slow;
                slow = temp;
            }  
        }
        while(slow && fast){
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

// slow扫描的时候把所有的指针反过来，fast的步子是slow的两杯，
// 最后扫描的时候就只要slow 设置为slow->next = prev 理论上是slow的前一个，实际上因为是指针已经反过来了，所以相当于第一个
// 注意一下prev, temp, slow那边写指针反转的代码
