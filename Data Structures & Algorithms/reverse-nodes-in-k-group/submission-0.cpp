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

    vector<ListNode*> helper(int k, ListNode *n){

        ListNode* prev = NULL; 
        ListNode* tmp = n;
        int K = k;

        while(tmp && K)
            tmp = tmp->next, K--;
        if(K)
            return {n, NULL, NULL};
        tmp = n;
        while(tmp && k--){
            ListNode* x = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = x;
        }
       
        return {prev, n, tmp};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* tmp = head;
        head = NULL;

        ListNode* prev = NULL;
        while(tmp){
            auto a = helper(k, tmp);
            if(prev)
                prev->next = a[0];
            tmp = a[2];
            prev = a[1];
            if(!head)
            head = a[0];

        }
        return head; 

    }
};
