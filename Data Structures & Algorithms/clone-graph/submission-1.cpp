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

    map<Node*, Node*>mp;



    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
    mp.clear();
    queue<Node*>q;
    q.push(node);
    map<Node*, bool>vis;
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        if(vis.count(t))
            continue;
        vis[t] = true;
        Node* n = new Node(t->val);
        mp[t] = n;
        for(Node* a: t->neighbors){
            cout<<a->val<<"; ";
            if(!vis.count(a))
                q.push(a);
            }
    }
    q.push(node);
    vis.clear();
     while(!q.empty()){
        Node* t = q.front();
        q.pop();
        if(vis.count(t))
            continue;
        vis[t] = true;
        Node* n = mp[t];
        for(Node* a: t->neighbors){
            n->neighbors.push_back(mp[a]);
            if(!vis.count(a))
                q.push(a);
        }
    }
    // q.push(mp[node]);
    // vis.clear();
    // while(!q.empty()){
    //     Node* t = q.front();
    //     q.pop();
    //     if(vis.count(t))    
    //         continue;
    //     vis[t] = true; 
    //     cout<<t->val<<" ";
    //     for(Node* a: t->neighbors)
    //         if(!vis.count(a))
    //             q.push(a);
    // }
    return mp[node];
    

    }
};
