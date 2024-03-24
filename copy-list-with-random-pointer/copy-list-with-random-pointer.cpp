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
        map<Node*, Node*> mp;
        Node* cur = head;
        
        while(cur){
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        
        for(auto x : mp){
            x.second->next = mp[x.first->next];
            x.second->random = mp[x.first->random];
        }        
        return mp[head];
    }
};