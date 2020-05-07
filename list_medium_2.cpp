//https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/784/

// 整体的算法比较简单，就是看见是odd的就往后放，但是还是延续了list的特点，特别容易在细节方面出错
// 开始第一次 if(p->next == NULL) break; 这个没有，如果是两个节点就会丢失一个节点
// dummy的用到了还是很有效果的
// 
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        int sum = 0;
        ListNode* tail = dummy;
        while(tail->next != NULL){
            tail = tail->next;
            sum++;
        }
        for(int i = 0;i < sum;i++){
            if(i%2 == 1){
                if(p->next == NULL) break;
                ListNode* temp = p;
                pre->next = temp->next;
                p = p->next;
                tail->next = temp;
                tail = tail->next;
                temp->next = NULL;
            }else{
                p = p->next;
                pre = pre->next;
            }
            // for(ListNode* q = head;q!= NULL;q = q->next) cout << q->val << ends;
            // cout << endl;
        }
        return dummy->next;
    }
};

// The solution is very intuitive. But it is not trivial to write a concise and bug-free code.
// solution 对这道题目的评价
// solution的java题解
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        ListNode odd = head, even = head.next, evenHead = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
}
// 这个在找到even的节点之后没有立刻接到tail后面，而是先组成一个even的list最后把两个list合并。
