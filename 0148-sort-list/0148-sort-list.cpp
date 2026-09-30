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
    ListNode* mergeSort(ListNode* head){
        if(head==nullptr || head->next== nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode*pre=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=nullptr;
        ListNode* head1=mergeSort(head);
        ListNode* head2=mergeSort(slow);
        ListNode* ans=merge(head1,head2);
        return ans;
    }
    ListNode* merge(ListNode* head1 , ListNode*head2){
        if(head1==nullptr)return head2;
        if(head2==nullptr)return head1;
        if(head1->val <= head2->val){
            head1->next = merge(head1->next,head2);
            return head1;
        }else{
            head2->next = merge(head1,head2->next);
            return head2;
        }
        return nullptr;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* finalAns = mergeSort(head);
        return finalAns;
    }
};