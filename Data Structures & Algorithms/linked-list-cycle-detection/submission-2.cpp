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
    bool hasCycle(ListNode* head) {
        
        if(!head)
            return false;
        
        if(!head->next)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next->next; 

        while(fast && slow)
        {
            if(fast == slow)
                return true;
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return false;
            slow = slow->next;

        }
        return false; 

    }
};
