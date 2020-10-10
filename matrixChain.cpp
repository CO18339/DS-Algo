#include<iostream>
#include<climits>
#include<iomanip>
using namespace std;

void print(int s[][7],int i,int j)
{
	if(i==j)
		cout<<"A"<<i<<" ";
	else
	{
		cout<<"( ";
		print(s,i,s[i][j]);
		print(s,s[i][j]+1,j);
		cout<<" )";
	}
}

int main()
{
	int n=6;
	int p[]={30,35,15,5,10,20,25};

	int m[7][7];
	int s[7][7];

	int min;
	int j;
	int count=1;

	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;
	}

	for(int l=2;l<=n;l++)
	{
		// cout<<"Length: "<<l<<endl;
		// cout<<"Number of subproblems: "<<n-l+1<<endl;
		// cout<<"\nSubproblems: \n";
		for(int i=1;i<=n-l+1;i++)
		{
			
			j=i+l-1;
			m[i][j]=INT_MAX;
			// cout<<count<<") A"<<i<<".."<<j<<endl;
			// cout<<"m"<<"["<<i<<"]"<<"["<<j<<"] = "<<"min{"<<endl;
			// cout<<endl;
			for(int k=i;k<=j-1;k++)
			{
				// cout<<"m"<<"["<<i<<"]"<<"["<<k<<"]"<<" + ";
				// cout<<"m"<<"["<<k+1<<"]"<<"["<<j<<"]"<<" + ";
				// cout<<"p["<<i-1<<"]"<<"p["<<k<<"]"<<"p["<<j<<"] =";
				min=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				// cout<<min<<endl;
				if(min<m[i][j])
				{
					m[i][j]=min;
					s[i][j]=k;
				}

			}
			// cout<<endl;
			// cout<<"}"<<endl;
			// cout<<"Therefore: m"<<"["<<i<<"]"<<"["<<j<<"]"<<" = "<<min<<endl;
			// cout<<endl;
			// count++;

		}
		// count=1;
		// cout<<endl;
	}

	for(int j=n;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{	
			if(i<=j)
			cout<<setw(10)<<m[i][j];	
		}
		cout<<endl;
	}

	cout<<endl;

		for(int j=n;j>=2;j--)
	{
		for(int i=1;i<=n-1;i++)
		{	
			if(i<j)
			cout<<setw(10)<<s[i][j];	
		}
		cout<<endl;
	}

	cout<<"Solution:"<<endl;

	print(s,1,6);


	return 0;
}
