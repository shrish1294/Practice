/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
            cout<<node->val<<" ";
        map<Node*, Node*>mp;
        queue<Node*>pq;
        pq.push(node);
        while(!pq.empty()){
            Node* n = pq.front();
            pq.pop();
            if(mp.find(n)!=mp.end())
                continue;
            Node* cp = new Node(n->val);
            mp[n] = cp;
            int size = n->neighbors.size();
            for(int i  = 0;  i < size; i++){
                if(!n->neighbors[i])
                    continue;
                if(mp.find(n->neighbors[i])!=mp.end())
                    continue;
                pq.push(n->neighbors[i]);
            }
        }
        pq.push(node);
        map<Node*, bool>vis; 
        vis[node] = true;
        while(!pq.empty()){
            Node* n = pq.front();
            pq.pop();

            int size = n->neighbors.size();
            Node* cp = mp[n];
            for(int i = 0;  i < size; i++){
                if(!n->neighbors[i])
                    continue;
                cp->neighbors.push_back(mp[n->neighbors[i]]);
                if(vis[n->neighbors[i]])
                    continue;
                pq.push(n->neighbors[i]);
                vis[n->neighbors[i]] = true;
            }
        }
        return mp[node];

        
    }
};
