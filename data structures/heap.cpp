#include<bits/stdc++.h>
using namespace std;
vector<int> heap;
int size;
int getparentindex(int index){ return (index-1)/2;
}
int getleftchild(int index){ return index*2 + 1 ;
}
int getrightchild(int index){ return index*2 + 2 ;
}

void swap(int index,int swapindex)
{
	int swapval=heap[index];
	heap[index]=heap[swapindex];
	heap[swapindex]=swapval;
}


void heapifydown(int index){
	while(index<size)
	{
		if( getleftchild(index) < size && heap[index]<heap[getleftchild(index)] && getrightchild(index) < size &&  heap[index] <heap[getrightchild(index)])
			break;
		else
		{
			if( getleftchild(index) < size && getrightchild(index) < size && heap[getleftchild(index)] < heap[getrightchild(index)])
				{
					swap(index,getleftchild(index));
					index=getleftchild(index);
				}
			else if( getleftchild(index) < size && getrightchild(index) < size && heap[getleftchild(index)] > heap[getrightchild(index)] )
			{
				swap(index,getrightchild(index));
				index=getrightchild(index);
			}
			else if( getleftchild(index) < size && heap[getleftchild(index)] < heap[index])
				{
					swap(index,getleftchild(index));
					index=getleftchild(index);
				}
			else
			{
				return;
			}
		}
	}
}

void heapifyup(int index)
{
	while(true)
	{
		if(heap[index]<heap[getparentindex(index)])
		{
			swap(index,getparentindex(index));
			index=getparentindex(index);
		}
		else
		{
			break;
		}
	}
}

void makeheap()
{
	for(int i=heap.size()/2;i>=0;i--)	
	{
		heapifydown(i);
	}
}

void heapinsert(int val)
{
	heap.push_back(val);
	heapifyup(size);
	size++;
}


int main(){
	heap=vector<int>{12, 11, 13, 5, 6, 7};
	size=heap.size();
	makeheap();
	heapinsert(0);
	for(int i=0;size;)
		{
			cout<<heap[i]<<" ";
			swap(i,size-1);size--;
			heapifydown(i);
		}
}
