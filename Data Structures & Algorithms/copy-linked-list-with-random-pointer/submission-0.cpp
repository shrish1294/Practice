/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<Node*, Node*>mp;
        Node* tmp = head;
        while(tmp){
            Node* n = new Node(tmp->val);
            mp[tmp] = n;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            
            Node* n = mp[tmp];
            Node*nxt = NULL;
            Node* rdm  = NULL; 
            if(tmp->next)
                nxt = mp[tmp->next];
            if(tmp->random)
                rdm = mp[tmp->random];
            n->next = nxt;
            n->random = rdm;
            tmp = tmp->next;
        }
        return mp[head];

    }
};
