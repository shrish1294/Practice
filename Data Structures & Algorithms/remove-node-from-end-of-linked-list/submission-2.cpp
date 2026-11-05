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
        while(k)
            len++, k = k->next;
        
        int N = len - n;
        ListNode* prev = head;
        k = head;
        if(N == 0)
            return head->next;
        int a = 1;
        while(a < N){
            k = k->next;
            prev = k; 
            a++; 
        }
        // cout<<prev->val<<" ";
        if(k->next)
        prev->next = k->next->next;
        else
            prev->next = NULL; 
        return head; 
    }
};
