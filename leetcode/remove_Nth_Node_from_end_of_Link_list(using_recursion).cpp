/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool flag=false;
    int deletenode(ListNode *temp,ListNode* temp1 ,int i,int n)
    {
        if(temp1==NULL)
        {
            return 0;
        }
        else
        {
            i= 1 + deletenode(temp->next,temp1->next,i,n);
            if(i==n)
            {
                temp->next=temp1->next;
                this->flag=true;
            }
            return i;
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int j=deletenode(head,head->next,0,n);
        if(j==0){
            head=NULL;
        }
        else if(!this->flag){
            head=head->next;
        }
        ListNode* temp=head;
        while(temp!=NULL)
        {
            //cout<<temp->val<<endl;
            temp=temp->next;
        }
        return head;
    }
};
