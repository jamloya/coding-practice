
#include<bits/stdc++.h>

using namespace std;
class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};

class Node
{
 public:
 		int val;
 		Node *next;
 		
  Node(int value) : val(value),next(nullptr) {}
};

class doubleNode
{
	public:
		int val;
		doubleNode *next,*prev;
		
	doubleNode(int value) : val(value) ,prev(nullptr),next(nullptr) {}
};

void printPreOrder(TreeNode* root)
{
	 if(root==nullptr) return;
	 cout<<root->val<<" ";
	 printPreOrder(root->left),printPreOrder(root->right);
}

bool isVowel(char c)
{
	 return c=='a' || c=='A' || c=='e' || c=='E' ||
	 c=='i' || c=='I' || c=='o' || c=='O' ||
	 c=='u' || c=='U' ;
}

class FirstUnique{
public:
	   FirstUnique(vector<int> nums){
	   		this->head=new doubleNode(0);
	   		doubleNode* current=head;
	   		for(auto i:nums)
	   		{
	   			if(track.find(i)!=track.end())
			   	{
			   		if(track[i].first==false)
					{
						doubleNode *temp=track[i].second;
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
						delete(temp);
						track[i].first=true;		   	
					}
				}
				else
				{
					doubleNode* newNode=new doubleNode(i);
					newNode->prev=current;
					current->next=newNode;
					track[i]={false,newNode};
					current=current->next;
				}
			}
			this->tail=current;
			
	   }
	   
	   
	   void add(int val)
	   {
	   		
	   		if(track.find(val)!=track.end())
	   		{
	   			if(track[val].first==false)
	   			{
					doubleNode *temp=track[val].second;
					
					if(temp==tail)
					{
						tail=tail->prev;
					}
					temp->prev->next=temp->next;
					if(temp->next!=nullptr)
						temp->next->prev=temp->prev;
					delete(temp);
					
					
					track[val].first=true;
				}
			}
			else
			{
				this->tail->next=new doubleNode(val);
				this->tail=this->tail->next;
				track[val]={false,this->tail};
			}
	   }
	   
		int showFirstUnique()
		{
//				for(auto i(tail);i!=head;i=i->prev) cout<<i->val<<" ";
//					cout<<endl;
//				for(auto i(head);i!=nullptr;i=i->next) cout<<i->val<<" ";
//				cout<<endl;
//					
			return head->next==nullptr?-1:head->next->val;
		}
private:
	unordered_map<int,pair<bool,doubleNode*>> track;
	doubleNode *head,*tail;
};

int main()
{
		
	 clock_t t;
	 t=clock();
	 FirstUnique firstUnique({2,3,5});
	cout<<firstUnique.showFirstUnique(); // return 2
	firstUnique.add(5);            // the queue is now [2,3,5,5]
	cout<<endl<<firstUnique.showFirstUnique(); // return 2
	firstUnique.add(2);            // the queue is now [2,3,5,5,2]
	cout<<endl<<firstUnique.showFirstUnique(); // return 3
	firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
	cout<<endl<<firstUnique.showFirstUnique(); // return -1
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

