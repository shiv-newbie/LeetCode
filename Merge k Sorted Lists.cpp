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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans=new ListNode;
        ListNode* tmp=ans;
        int lastNum=-100000;
        while(true){
            bool toBreak=true;
            int mn=10000, mini=0;
            for(int i=0;i<lists.size();i++){
                if(lists[i]!=NULL){
                    toBreak=false;
                }else{
                    continue;
                }
                if(lists[i]->val<mn){
                    mn=lists[i]->val;
                    mini=i;
                    if(lastNum==lists[i]->val)break;
                }
            }
            if(toBreak)break;
            tmp->next= new ListNode;
            tmp=tmp->next;
            tmp->val=lists[mini]->val;
            lastNum=tmp->val;
            lists[mini]=lists[mini]->next;
        }
        return ans->next;
    }
};
