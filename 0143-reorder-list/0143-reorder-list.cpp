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
    ListNode* secondList(ListNode*head){
        if(head== nullptr || head->next==nullptr)return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* newHead=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        newHead=slow->next;
        slow->next=nullptr;
        return newHead;
    }
    ListNode* reverse(ListNode* head){
        if(head== nullptr || head->next==nullptr)return head;
        ListNode* pre=nullptr;
        ListNode*curr=head;
        ListNode*nex=nullptr;
        while(curr!=nullptr){
            nex=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(head== nullptr || head->next==nullptr || head->next->next==nullptr)return;
        ListNode* newHead=secondList(head);
        ListNode* t1= head;
        ListNode* t2=reverse(newHead);
        while(t2!=nullptr){
            ListNode* m1 = t1->next;
            ListNode* m2=t2->next;
            t1->next=t2;
            t2->next=m1;
            t1=m1;
            t2=m2;
        } 
        return;

    }
};