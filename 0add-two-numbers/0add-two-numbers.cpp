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

class ListNode2{
    int val;
    ListNode2* next;
    ListNode2() : val(0), next(nullptr){}
    ListNode2(int x) : val(x), next(nullptr){}
    ListNode2(int x, ListNode2* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int carry = 0;
        while( l1 || l2 || carry ){
            int x = 0, y = 0;
            if( l1 ){
                x = l1->val;
                l1 = l1->next;
            }
            if( l2 ){
                y = l2->val;
                l2 = l2->next;
            }
            int num = x + y + carry;
            tail->next = new ListNode(num % 10);
            carry = num / 10;
            tail = tail->next;
            
        }
        return dummy->next;
    }
};