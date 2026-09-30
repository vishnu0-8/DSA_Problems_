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
    ListNode* Merge(ListNode* l1, ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val <= l2->val){
            l1->next=Merge(l1->next,l2);
            return l1;
        }else{
            l2->next=Merge(l1,l2->next);
            return l2;
        }
        return nullptr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* ans=nullptr;
        for(int i=0;i<lists.size();i++){
            ans=Merge(ans,lists[i]);
        }
        return ans;

    }
};