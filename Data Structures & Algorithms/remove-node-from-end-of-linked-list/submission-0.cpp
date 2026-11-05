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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* k = head;
        while(k){
            k = k->next;
            len++;
        }
        len-=n;
        if(len == 0)
            return head->next;

        k = head;
        while(len-1 > 0){
            k = k->next;
            len--;
        }
        if(k){
            if(k->next)
                k->next = k->next->next;
        }
        return head; 
        
    }
};
