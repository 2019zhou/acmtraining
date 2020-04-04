//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/773/


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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        unordered_map<ListNode*, int> mp;
        while(p!= NULL){
            if(mp[p] > 0) return true;
            mp[p]++;
            p = p->next;
        }
        return false;
    }
};


// 这里时间空间都不够优化，使用快慢指针应该可以大大提高这两点

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// 注意快慢指针的初始值的设定 slow = head , fast = head->next
// 另外 判断条件，判断false的比较顺，但是也比较精巧
// slow 每次前进一步，fast每次前进两步，总是需要变成一起的
