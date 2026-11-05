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

        ListNode* last = NULL; 
        ListNode* node = head;
        while(node){
            ListNode* t = node->next; 
            node->next = last;
            last = node;
            node = t;
        }
        return last; 
    }
};
