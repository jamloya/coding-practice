class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* merge=new ListNode(0);
        if(l1==nullptr && l2==nullptr){return l1;}
        else if(l1==nullptr){return l2;}
        else if(l2==nullptr){return l1;}
        merge=l1->val<l2->val?l1:l2;
        merge==l1?l1=l1->next:l2=l2->next;
        ListNode* temp=merge;
        while(l1!=NULL && l2!=NULL)
        {
            l1->val<l2->val?temp->next=l1:temp->next=l2;
            temp->next==l1?l1=l1->next:l2=l2->next;
            temp=temp->next;
            //cout<<l1->val;
        }
        if(l1==NULL)
        {
            temp->next=l2;
        }
        else 
        {
            temp->next=l1;
        }
        return merge;
    }
};
