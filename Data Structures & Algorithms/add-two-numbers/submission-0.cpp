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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* n = NULL; 
    ListNode* head = NULL ; 
    int cry = 0;
     while(l1 && l2){
        int val = l1->val + l2 -> val + cry;
        cry = val / 10;
        val = val % 10;
        if(!n){
            n = new ListNode(val);
            head = n;
        }
        else{
            n->next = new ListNode(val);
            n = n->next;
        }
        l1 = l1 -> next;
        l2 = l2 -> next;
     }
     while(l1){
        int val = l1->val +  cry;
        cry = val / 10;
        val = val % 10;
        if(!n){
            n = new ListNode(val);
            head = n;
        }
        else{
            n->next = new ListNode(val);
            n = n->next;
        }
        l1 = l1 -> next;
     }
     while(l2){
        int val = l2 -> val + cry;
        cry = val / 10;
        val = val % 10;
        if(!n){
            n = new ListNode(val);
            head = n;
        }
        else{
            n->next = new ListNode(val);
            n = n->next;
        }
        l2 = l2 -> next;
     }
     while(cry){
        n->next = new ListNode(cry % 10);
        n = n->next;
        cry/=10;
     }
        return head; 
    }
};
