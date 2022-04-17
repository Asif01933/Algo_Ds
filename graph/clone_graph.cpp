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
        if(!node){
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        Node* copy= new Node(node->val);
        mp[node]=copy;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* protibeshi=q.front();
            q.pop();
            for(Node* protibeshir_protibeshi: protibeshi->neighbors){
                if(!mp.count(protibeshir_protibeshi)){
                    mp[protibeshir_protibeshi]=new Node(protibeshir_protibeshi->val);
                    q.push(protibeshir_protibeshi);
                }
                mp[protibeshi]->neighbors.push_back(mp[protibeshir_protibeshi]);
            }
        }
        return copy;
        
    }
};