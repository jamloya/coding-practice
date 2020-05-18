#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *odd,*evenHead,*even;
        odd=head;
        evenHead=head->next;
        even=evenHead;
        
        while(even!=nullptr && even->next!=nullptr)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=evenHead;
        return head;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

