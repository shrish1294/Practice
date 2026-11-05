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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode* head = NULL;
        ListNode* tmp = head;

        while(list1 && list2){

            if(head==NULL){
                if(list1->val > list2->val){
                    head = list2;
                    cout<<"Fef";
                    tmp = head;
                    list2 = list2->next;
                }
                else{
                    head = list1;
                    tmp = head;
                    cout<<"Fef";
                    list1 = list1->next;
                }
            }
            else{
                if(list1->val > list2->val){
                    tmp->next = list2;
                    list2 = list2->next;
                    tmp = tmp->next;
                }
                else{
                    tmp->next = list1;
                    list1 = list1->next;
                    tmp = tmp->next;
                    
                }
            }   
        }

        if(list1)
            tmp->next = list1;
        if(list2)
            tmp->next = list2; 


        return head;
        
        


    }
};
