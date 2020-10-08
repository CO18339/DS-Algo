#include<iostream>
using namespace std;


template<typename T>
struct node
{
	T key;
	struct node* next;
	struct node* prev;
};

template<typename T>
class LinkedList
{
	node<T> *HeaderNode;

	public:
	LinkedList();
	void insertAtBeg(node<T>*);
	void deleteFromLinkedList(T);
	node<T>* SearchLinkedList(T);
	void display(); 
};

template<typename T>
LinkedList<T>::LinkedList()
{
	//Header Node
	this->HeaderNode=new node<T>;
	this->HeaderNode->key=0;
	this->HeaderNode->next=this->HeaderNode;
	this->HeaderNode->prev=this->HeaderNode;
}

template<typename T>
void LinkedList<T>::insertAtBeg(node<T> *newNode)
{
	//Insert at beginning
	newNode->next=this->HeaderNode->next;
	this->HeaderNode->next->prev=newNode;
	this->HeaderNode->next=newNode;
	newNode->prev=this->HeaderNode;
}

template<typename T>
void LinkedList<T>::display()
{
	node<T>* tempNode;
	tempNode=this->HeaderNode->next;
	while(tempNode!=this->HeaderNode)
	{
		cout<<tempNode->key<<" ";
		tempNode=tempNode->next;
	}
	cout<<endl;
}

template<typename T>
void LinkedList<T>::deleteFromLinkedList(T key)
{
	node<T>* remove=SearchLinkedList(key);
	if(remove!=this->HeaderNode)
	{
		remove->prev->next=remove->next;
		remove->next->prev=remove->prev;
	}
	else
	{
		cout<<"Key value not found"<<endl;
	}
}

template<typename T>
node<T>* LinkedList<T>::SearchLinkedList(T key)
{
	node<T>* tempNode = this->HeaderNode->next;
	while(tempNode!=this->HeaderNode && tempNode->key!=key)
	{
		tempNode=tempNode->next;
	}
	return tempNode;
}

int main()
{
	LinkedList<int> L;
	node<int> *temp;

	temp = new node<int>;
	temp->key=4;
	L.insertAtBeg(temp);

	temp=new node<int>;
	temp->key=3;
	L.insertAtBeg(temp);

	temp=new node<int>;
	temp->key=2;
	L.insertAtBeg(temp);

	temp=new node<int>;
	temp->key=1;
	L.insertAtBeg(temp);

	L.deleteFromLinkedList(6);
	L.display();

	return 0;
}
