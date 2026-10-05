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
    ListNode* partition(ListNode* head, int x) {

        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* smallTail = small;
        ListNode* largeTail = large;

        ListNode* curr = head;

        while (curr != nullptr) {

            if (curr->val < x) {
                smallTail->next = curr;
                smallTail = smallTail->next;
            }
            else {
                largeTail->next = curr;
                largeTail = largeTail->next;
            }

            curr = curr->next;
        }

        
        largeTail->next = nullptr;

        // Connect small list with large list
        smallTail->next = large->next;

        return small->next;
    }
};