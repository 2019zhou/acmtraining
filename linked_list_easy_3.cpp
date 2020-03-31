//reverse the list

//get confused at next->next->next ?????

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode(0), *cur = head;
        pre -> next = head;
        while (cur && cur -> next) {
            ListNode* temp = cur -> next;
            cur -> next = temp -> next;
            temp -> next = pre -> next;
            pre -> next = temp;
        }
        return pre -> next;
    }
};

//here is my brute force answer, waste much memory
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        stack<int> store;
        while(p != NULL) {
            store.push(p->val);
            p = p->next;
        }
        p = head;
        while(p != NULL){
            p->val = store.top();
            store.pop();
            p = p->next;
        }
        return head; 
    }
};
