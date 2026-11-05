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
    ListNode* reverseList(ListNode* head) {
        
        ListNode*tmp = head;
        if(!head || !head->next)
            return head; 
        ListNode* p = NULL;  

        while(tmp){

            ListNode* x = tmp->next;
            tmp->next = p; 
            p = tmp; 
            tmp = x; 
        }
        head = p;
        return head;

    }
};
