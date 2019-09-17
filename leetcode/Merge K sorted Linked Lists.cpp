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
    ListNode* MergeSort(ListNode* l1,ListNode* l2)
    {
        if(l1==nullptr && l2==nullptr)
        {
            return nullptr;
        }
        else if(l1==nullptr )
        {
            return l2;
        }
        else if(l2==nullptr)
        {
            return l1;
        }
        ListNode* temp=l1->val<l2->val?l1:l2;
        ListNode* temphead=temp;
        temp==l1?l1=l1->next:l2=l2->next;
        while(l1!=NULL && l2!=NULL)
        {   
            if(l1->val<l2->val)
            {   ListNode* temp1=new ListNode(l1->val);
                temp->next=temp1;
                temp=temp1;
             l1=l1->next;
            }
            else
            {
                ListNode* temp1=new ListNode(l2->val);
                temp->next=temp1;
                temp=temp1;
                l2=l2->next;
            }
        }
        if(l1==NULL)
        {
            temp->next=l2;
        }
        else if(l2==NULL)
        {
            temp->next=l1;
        }
        return temphead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* res=MergeSort(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++)
        {
            res=MergeSort(res,lists[i]);
        }
        return res;
    }
};
