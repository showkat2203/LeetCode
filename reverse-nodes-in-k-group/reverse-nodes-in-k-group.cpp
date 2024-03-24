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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        for(int i = 0; i < k; i++ ){
            if( !current ) return head;
            current = current->next;
        }

        current = head;
        ListNode* prev = nullptr, *_next = nullptr;

        for(int i = 0; i < k; i++ ){
            _next = current->next;
            current->next = prev;
            prev = current;
            current = _next;
        }
        head->next = reverseKGroup(current, k);

        return prev;
    }
};