#include<iostream>
#include<limits.h>
using namespace std;
int RodCutting(int *price,int n,int *r)
{
	int q=INT_MIN;
	if(r[n-1]>=0)
		return r[n-1];
	if(n-1==0)
		return 0;
	else
	{
		
		for(int i=0;i<n;i++)
		{
			q=max(q,price[i]+RodCutting(price,n-1-i,r));
		}
		
	}
	r[n-1]=q;
	return q;
}
int main()
{
	int price[]={1,5,8,9,10,17,17,20,24,30};
	int length=sizeof(price)/sizeof(int);
	int *r= new int[length];
	for(int i=0;i<length;i++)
	{
		*(r+i)=INT_MIN;

		cout<<r[i]<<endl;
	}
	int n=10;
	
	cout<<RodCutting(price,n,r)<<endl;
	
	return 0;
}
