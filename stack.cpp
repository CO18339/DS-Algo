#include<iostream>
using namespace std;
#define MAX_SIZE 10

template<typename T>
class stack
{
	T *arr;
	int top;
	int capacityOfStack;
	int maxSize=MAX_SIZE;

public:

	stack();
	int capacity();
	void setCapacity(int);
	int size();
	void push(T element);
	T pop();
	bool isStackEmpty();
	bool isStackFull();
	void display();  // This method won't work if you will work with multidimensional stack

};

template<typename T>
stack<T>::stack()
{
	this->arr=0;
	this->capacityOfStack=0;
	this->top=-1;
	
	// cout<<"Stack generted of 0 size"<<endl;
}

template<typename T>
void stack<T>::push(T element)
{
	if(this->capacity()==this->size())
	{
		T *temp;
		temp = new T[this->capacity() + 4];
		for(int i = this->top ; i >= 0 ; i--)
		{
			temp[i]=arr[i];
		}
		// cout<<"Reallocating memory"<<endl;
		setCapacity(this->capacity()+4);
		delete arr;
		arr=temp;
	}

	if(isStackFull())
	{
		cerr<<"Overflow";
		exit(0);
	}

	else
	{
		this->top+=1;
		arr[this->top]=element;
	}
	
}

template<typename T>
T stack<T>::pop()
{
	if(this->capacity() - this->size() == 5)
	{
		T *temp;
		temp = new T[this->capacity()-4];

		for(int i = this->top; i>=0; i--)
		{
			temp[i]=arr[i];
		}

		setCapacity(this->capacity()-4);
		delete arr;
		arr=temp;
	}
	if(isStackEmpty())
	{
		cerr<<"Underflow";
		exit(0);
	}
	else
	{
		T element = arr[this->top];
		this->top-=1;
		return element;
	}
}

template<typename T>
bool stack<T>::isStackEmpty()
{
	if(this->top==-1)
		return true;
	else
		return false;
}

template<typename T>
bool stack<T>::isStackFull()
{
	if(this->maxSize==this->size())
	{
		return true;
	}
	else
		return false;
}

template<typename T>
int stack<T>::size()
{
	return this->top+1;
}

template<typename T>
int stack<T>::capacity()
{
	return capacityOfStack;
}

template<typename T>
void stack<T>::setCapacity(int argument)
{
	this->capacityOfStack = argument;
}

template<typename T>
void stack<T>::display()
{
	for(int i = this->top; i>=0 ;i--)
	{
		cout<<*(arr + i);
		cout<<endl;
	}
}

int main()
{
	return 0;
}
