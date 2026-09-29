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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp != nullptr){
            count++;
            temp=temp->next;
        }
        if(n>count){
            return nullptr;
        }
        if(n==count){
            head=head->next;
            return head;
        }
        temp=head;
        if(n==1){
            while(temp->next->next!=nullptr){
                temp=temp->next;
            }
            temp->next=nullptr;
            return head;
        }
        for(int i = 1 ; i<(count-n);i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;

    }
};