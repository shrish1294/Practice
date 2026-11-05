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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, 
        greater<pair<int, ListNode*>>>pq;

        ListNode* head = NULL;
        ListNode* t = NULL;
        for(ListNode* a: lists){
            if(a)
                pq.push({a->val, a});
        }
        while(!pq.empty()){
           auto x = pq.top();
            pq.pop();
            if(x.second->next)
                pq.push({x.second->next->val, x.second->next});
            if(!head){
                head = x.second;
                t = head;    
            }
            else{
                t->next = x.second;
                t = t->next;
                }
        }
        return head;
       
        
    }
};
