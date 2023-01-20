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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> values;
        vector<int> allValues;
        while(head!=NULL){
            values.push_back(head->val);
            if(values.size()==k){
                reverse(values.begin(),values.end());
                allValues.insert(allValues.end(), values.begin(), values.end());
                values.clear();
            }
            head=head->next;
        }
        allValues.insert(allValues.end(), values.begin(), values.end());

        ListNode* allNodes=new ListNode;
        ListNode* tmp=allNodes;
        cout<<allValues.size()<<"\n";
        for(int i=0;i<allValues.size();i++){
            tmp->next=new ListNode;
            tmp=tmp->next;
            tmp->val=allValues[i];
        }
        return allNodes->next;
    }
};
