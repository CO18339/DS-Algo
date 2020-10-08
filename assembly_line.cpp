#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	//length of assembly line
	int l;
	cin>>l;

	int fopt = -1;
	int lopt = -1;
	int e1,e2,x1,x2;
	cin>>e1>>e2>>x1>>x2;

	vector<int> f1(l),f2(l),l1(l),l2(l),a1(l),a2(l),t1(l-1),t2(l-1);
	a1 = {7,9,3,4,8,4};
	a2 = {8,5,6,4,5,7};

	t1 = {2,3,1,3,4};
	t2 = {2,1,2,2,1};

	//BASE cases
	f1[0] = e1 + a1[0];
	f2[0] = e2 + a2[0];

	for(int j=1;j<=l-1;j++){
		if(f1[j-1] + a1[j]< f2[j-1] + a1[j] + t2[j-1]){
			f1[j] = f1[j-1] + a1[j];
			l1[j] = 1;
		}
		else{
			f1[j] = f2[j-1] + a1[j] + t2[j-1];
			l1[j] = 2;
		}

		if(f2[j-1] + a2[j] < f1[j-1] + a2[j] + t1[j-1]){
			f2[j] = f2[j-1] + a2[j];
			l2[j] = 2;
		}
		else{
			f2[j] = f1[j-1] + a2[j] + t1[j-1];
			l2[j] = 1;
		}
	}

	if(f1[l-1] + x1 < f2[l-1] + x2){
		fopt = f1[l-1] + x1;
		lopt = 1;
	}
	else
	{
		fopt = f2[l-1] + x2;
		lopt = 2;
	}
	cout<<"Value: "<<fopt<<endl;
	//printing path
	cout<<"Path"<<endl;
	cout<<lopt<<",";
	int ptr = lopt;
	for(int j=l-1;j>=1;j--){
		if(ptr == 1){
			cout<<l1[j]<<",";
			ptr = l1[j];
		}
		else{
			cout<<l2[j]<<",";
			ptr = l2[j];
		}

	}
	return 0;
}
