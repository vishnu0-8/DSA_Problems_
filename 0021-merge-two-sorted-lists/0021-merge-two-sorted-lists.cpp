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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(0);
        ListNode* temp3=list3;
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val>=list2->val){
                temp3->next=list2;
                list2=list2->next;
            }
            else{
                temp3->next=list1;
                list1=list1->next;
            }
            temp3=temp3->next;
        }
        while(list1!=nullptr){
            temp3->next=list1;
            list1=list1->next;
            temp3=temp3->next;
        }
        while(list2!=nullptr){
            temp3->next=list2;
            list2=list2->next;
            temp3=temp3->next;
        }
        return list3->next;
    }
};