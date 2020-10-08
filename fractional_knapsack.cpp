#include<iostream>
#include"linkedList.h"
using namespace std;

template<typename T>
class priorityQueue
{
	LinkedList<T> L;
	
public:
	
	priorityQueue();
	void insert(T val,T wt);
	node<T>* extractMax();
	void display();
	
};

template<typename T>
priorityQueue<T>::priorityQueue()
{
	
}
template<typename T>
void priorityQueue<T>::insert(T val,T wt)
{
	node<T>* temp = new node<T>;
	temp->value=val;
	temp->weight=wt;
	temp->key=val/wt;
	
	if(L.getHeaderNode()->next==L.getHeaderNode())
	{
		L.insertAtBeg(temp);
	}
	else
	{
		node<T>* ptr = L.getHeaderNode()->next;
		while(temp->key<ptr->key and ptr!=L.getHeaderNode())
		{
			ptr=ptr->next;
		}
		temp->next=ptr;
		temp->prev=ptr->prev;
		ptr->prev->next=temp;
		ptr->prev=temp;
	}
	
}

template<typename T>
node<T>* priorityQueue<T>::extractMax()
{
	node<T>* temp;
	temp= L.getHeaderNode()->next;
	if(temp!=L.getHeaderNode())
	{
		L.getHeaderNode()->next=temp->next;
		temp->next->prev=L.getHeaderNode();
		return temp;
	}
	else
		return L.getHeaderNode();
}

template<typename T>
void priorityQueue<T>::display()
{
	L.display();
}
int main()
{
	priorityQueue<int> Q;
	Q.insert(100,20);
	Q.insert(60,10);
	Q.insert(120,30);
	Q.display();
	
	int W;
	int profit=0;
	cin>>W;
	
	node<int>* temp=Q.extractMax();
	while(W!=0 and temp->key!=0)
	{
		
		if(temp->weight<=W)
		{
			profit+=temp->value;
			W=W-temp->weight;
			
		}
		else
		{
			profit+=W*temp->key;
			W=0;
		}
		
		temp=Q.extractMax();
	}
	
	cout<<profit<<endl;
	return 0;
}
