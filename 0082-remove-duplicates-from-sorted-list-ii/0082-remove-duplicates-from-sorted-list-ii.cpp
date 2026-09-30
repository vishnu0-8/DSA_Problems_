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
    ListNode* deleteDuplicates(ListNode* head) {
       
       ListNode* curr=head;
        ListNode* pre=nullptr;
        while(curr!=nullptr){
            if(curr->next!=nullptr &&curr->val==curr->next->val){
                int val=curr->val;
                while(curr!=nullptr && curr->val==val){
                    curr=curr->next;
                }
                if(pre!=nullptr){
                    pre->next=curr;
                }else{
                    head=curr;
                }
            }else{
                pre=curr;
                curr= curr->next;
            }
        }
        return head;
    }
};