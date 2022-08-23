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
    
    ListNode *temp;
    
    bool traverse(ListNode* leaf)
    {
        if( leaf == NULL )
            return true;
        
        bool is_pal = traverse(leaf->next) & (temp->val == leaf->val);
        
        temp = temp->next;
        
        return is_pal;
    }
    
    bool isPalindrome(ListNode* head) {
        
        int cnt = 0;
        temp = head;
        
        return traverse(head);
    }
};