#include<iostream>
using namespace std;
#define MAX_EXPANDABLE_LIMIT 5
template<typename T>
class queue
{
	T *arr;
	int tail;
	int head;
	int capacityOfQueue;

public:

	queue();
	void enqueue(T);
	T dequeue();
	int size();
	int capacity();
	void setCapacity(int);
	bool isQueueFull();
	bool isQueueEmpty();
	void display(); // wont work for nested queues

};

template<typename T>
queue<T>::queue()
{
	this->arr=0;
	this->head=0;
	this->tail=0;
	this->setCapacity(0);
	cout<<"Queue created of zero size"<<endl;
}

template<typename T>
void queue<T>::enqueue(T element)
{
	if(isQueueFull())
	{
		cerr<<"Overflow"<<endl;
		exit(0);
	}
	

	else
	{

		if(this->tail==this->capacity())
		{
			T *temp;
			temp = new T[this->capacity()+4];
			if(this->tail >= this->head)
			{
				for(int i=this->head; i<=this->tail - 1;i++)
				{
					temp[i]=arr[i];
				}

			}

			else
			{
				for(int i=this->head;i<=MAX_EXPANDABLE_LIMIT - 1;i++)
				{
					temp[i]=arr[i];
				}

				for(int i=0;i<=this->tail - 1;i++)
				{
					temp[i]=arr[i];
				}
			}
			cout<<"I have allocated some memory"<<endl;
			this->setCapacity(this->capacity()+4);
			delete arr;
			arr=temp;
		}

		this->arr[this->tail]=element;
		this->tail+=1;
		if(this->tail == MAX_EXPANDABLE_LIMIT)
		{
			this->tail = 0;
		}		
	}
}

template<typename T>
bool queue<T>::isQueueEmpty()
{
	return this->head==this->tail;
}

template<typename T>
bool queue<T>::isQueueFull()
{
	return this->head==this->tail + 1 || this->head==0 && this->tail==MAX_EXPANDABLE_LIMIT - 1;
}

template<typename T>
T queue<T>::dequeue()
{
	if(isQueueEmpty())
	{
		cerr<<"Underflow"<<endl;
		exit(0);
	}

	else
	{
		T element = this->arr[this->head];

		if(this->head==MAX_EXPANDABLE_LIMIT - 1)
		{
			this->head=0;
		}
		else
			this->head+=1;

		return element;
	}
}

template<typename T>
int queue<T>::capacity()
{
	return this->capacityOfQueue;
}

template<typename T>
void queue<T>::setCapacity(int argument)
{
	this->capacityOfQueue = argument;
}

template<typename T>
int queue<T>::size()
{
	if (this->tail >= this->head)
	{
		return this->tail-this->head;
	}
	else
	{
		return MAX_EXPANDABLE_LIMIT - this->head + this->tail; 
	}
}

template<typename T>
void queue<T>::display()
{
	if(this->tail >= this->head)
	{
		for(int i=this->head;i<=this->tail-1;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i=this->head;i<=MAX_EXPANDABLE_LIMIT-1;i++)
		{
			cout<<arr[i]<<" ";
		}
		for(int i=0;i<this->tail;i++)
		{
			cout<<arr[i]<<" "; 
		}
		cout<<endl;
	}
	cout<<"Head="<<this->head<<endl;
	cout<<"Tail="<<this->tail<<endl;
}
int main()
{

	queue<int> Q;
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);

	Q.display();
	cout<<Q.size();

	
	return 0;
}
