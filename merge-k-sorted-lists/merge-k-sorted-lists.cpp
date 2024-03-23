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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : lists){
            ListNode* tmp = x;
            while( x ){
                pq.push(x->val);
                x = x->next;
            }
        }
        ListNode* res = new ListNode();
        ListNode* newHead = res;
        while( !pq.empty() ){
            res->next = new ListNode(pq.top());
            res = res->next;
            pq.pop();
        }
        
        return newHead->next;
    }
};