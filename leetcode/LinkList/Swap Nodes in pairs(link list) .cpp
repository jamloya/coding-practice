ListNode* recur(ListNode* temp1,ListNode* temp2)
    {
        if(temp2==NULL) return temp1;
        else{
            if(temp2->next==NULL){temp1->next=NULL;
                                 temp2->next=temp1;
                                 return temp2;}
            else{ListNode* head=recur(temp2->next,temp2->next->next);
                 temp1->next=head;
                temp2->next=temp1;
                return temp2;}
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)return nullptr;
        if(head->next==nullptr) return head;
        return recur(head,head->next);
    }
