#include<iostream>
using namespace std;


class newException : public exception
{
public:
	const char * what() const throw(){
		return "New exception";
	}
};
int main()
{

	try
	{
		throw newException();	
	}
	catch(newException& e)	//our new exception
	{
		cout<<e.what()<<endl;	
	}
	catch(exception& e)
	{
		cout<<"Other exeptions";
	}

return 0;

}
