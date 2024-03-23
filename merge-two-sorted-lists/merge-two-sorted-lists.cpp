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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* newHead = dummy;
        
        while( l1 != nullptr && l2 != nullptr){
            if( l1->val <= l2->val ){
                dummy->next = new ListNode(l1->val);
                dummy = dummy->next;
                l1 = l1->next;
            }
            else{
                dummy->next = new ListNode(l2->val);
                l2 = l2->next;
                dummy = dummy->next;
            }
        }
        
        while( l1 != nullptr){
            dummy->next = new ListNode(l1->val);
            dummy = dummy->next;
            l1 = l1->next;
        }
        
         while( l2 != nullptr){
            dummy->next = new ListNode(l2->val);
             dummy = dummy->next;
            l2 = l2->next;
        }
        
        return newHead->next;
    }
};