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
    ListNode* reverse(ListNode* head){
        if(!head)
            return head;
        ListNode* k = head;
        ListNode* last = NULL;
        while(k){
            ListNode* p = k->next;
            k->next = last;
            last = k;
            k = p;  
        }
        head = last;
        return head;

    }
    void reorderList(ListNode* head) {
        if(!head)
            return ;
        int n = 0;
        ListNode* t = head;
        while(t){
            t = t->next;
            n++;
        }
        

        int N = n - ((n&1)?(n/2):n/2 - 1);
       
        t = head;
        ListNode* last = NULL; 
        while(N--){
            last = t; 
            t = t->next; 
        }
        last->next = NULL; 
        t = reverse(t);
       
        last = head;
        // while(t){
        //     cout<<t->val<<" ";
        //     t = t->next; 
        // }

        while(t && last){
            cout<<last->val<<" "<<t->val<<"\n";
           
            ListNode* p = last->next;
            last->next = t;
            t = t->next;
            last->next->next = p ; 
   
            
            last = last->next->next;
        }
        



    }
};
