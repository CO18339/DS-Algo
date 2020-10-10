#include<iostream>
#include<malloc.h>
using namespace std;





void create(int ***t,int r,int c)
{

	int i,j;

	(*t)=(int**)malloc(r*sizeof(int*));
	
	for(i=0;i<r;i++)
	{
		(*t)[i]=(int*)malloc(c*sizeof(int));
	}
	
}


void insert(int **p,int r,int c)
{
	cout<<"\nInput elements into matrix: \n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>p[i][j];
	}

}

void addition(int **p,int **q,int r,int c)
{
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		cout<<*(*(p+i)+j)+*(*(q+i)+j)<<"   ";
	}
	cout<<"\n";
}

}

void sub(int **p,int **q,int r,int c)
{
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		cout<<*(*(p+i)+j)-*(*(q+i)+j)<<"   ";
	}
	cout<<"\n";
}
}

void transpose(int **p,int r,int c)
{
	int **transpose;
	create(&transpose,c,r);
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		*(*(transpose+j)+i) = *(*(p+i)+j);
	}
	

}

for(int i=0;i<c;i++)
{
	for(int j=0;j<r;j++)
	{
		cout<<*(*(transpose+i)+j)<<"  ";
	}
	cout<<"\n";
	
}

free(transpose);
}
int main()
{
	int **p;
	int **q;
	cout<<"\nRunning"<<endl;
	
	int ch;
	int r,c;
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"\nRows: ";
		cin>>r;
		cout<<"\nColumns: ";
		cin>>c;
		create(&p,r,c);
		insert(p,r,c);

		create(&q,r,c);
		insert(q,r,c);
		
		addition(p,q,r,c);break;



		case 2: 
		cout<<"\nRows: ";
		cin>>r;
		cout<<"\nColumns: ";
		cin>>c;
		create(&p,r,c);
		insert(p,r,c);

		create(&q,r,c);
		insert(q,r,c);



		sub(p,q,r,c); break;
		case 3:
		cout<<"\nRows: ";
		cin>>r;
		cout<<"\nColumns: ";
		cin>>c;


		create(&p,r,c);
		insert(p,r,c);
		transpose(p,r,c); break;
		
		default: cout<<"\nfalse input!!!"<<endl;
	}

	free(p);
	return 0;
}