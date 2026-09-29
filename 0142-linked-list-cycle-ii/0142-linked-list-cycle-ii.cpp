/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pos=head;
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                break;
            }
        }
        if(fast!=slow){
            return nullptr;
        }
        while(slow!=pos){
            slow=slow->next;
            pos=pos->next;
        }
        return pos;

    }
};