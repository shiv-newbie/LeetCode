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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode;
        ListNode* tmp = l3;
        int carry=0;
        while(true){
            if(!(l1==NULL) && !(l2==NULL)){
                carry=l1->val+l2->val+carry;
                tmp->val=carry%10;
                carry/=10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(!(l2==NULL)){
                carry=l2->val+carry;
                tmp->val=carry%10;
                carry/=10;
                l2=l2->next;
            }
            else if(!(l1==NULL)){
                carry=l1->val+carry;
                tmp->val=carry%10;
                carry/=10;
                l1=l1->next;
            }
            if(l1==NULL && l2==NULL) break;
            tmp->next=new ListNode;
            tmp=tmp->next;
        }

        if(carry!=0){
            tmp->next=new ListNode;
            tmp=tmp->next;
            tmp->val=carry;
        }
        
        return l3;
    }
};
