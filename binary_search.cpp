#include<iostream>
using namespace std;
using namespace sample;
namespace sample 
{

	
	void binary_search(int arr[],int n,int ele)
	{
		int lower,upper,middle;
		lower=0;		//lower index of array
		upper=n-1;		//upper index of array
		middle=(lower + upper)/2;	//middle index of array
		int flag=0;
		while(lower <= upper)
		{
			if(arr[middle]==ele)
				{
				flag=1;
				cout<<"\nElement found at pos "<<middle+1<<endl;
				break;
				}
			else if(arr[middle]<ele)
			{
				lower+=1;			//This is done in order to move index forward
			}
			else
			{
				upper-=1;			//This is done in order to move index backward
			}

			middle=(lower + upper)/2;
		}
		if(flag==0)
		{
			cout<<"\nElement not found"<<endl;
		}
	}
}

int main()
{
	int n;		// number of elements
	int ele;	//element to be searched for
	int arr[25];


	cout<<"\nNumber of elemets : ";
	cin>>n;

	cout<<"\nEnter numbers in ascending order: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	//input
	}
	cout<<"\nElement to be searched for: ";
	cin>>ele;
	binary_search(arr,n,ele);		//function for searching
	return 0;

}