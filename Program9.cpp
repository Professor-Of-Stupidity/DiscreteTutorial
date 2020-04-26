/*input
2
0 1
1 1
10
*/
//Program to solve a homogeneous linear recurrence relation with constant coefficients given by user
//The program will input the order of the relation
#include <iostream>
using namespace std;

int main()
{
	int fn[100] = {};
	int coeff[100] = {};
	
	//order of the recurrence relation
	int order = 0;
	cin>>order;

	//entering the initial elements
	for (int i = 0; i< order; ++i)
	{
		cout<<"fn["<<i<<"] = ";
		cin>>fn[i];
		cout<<endl;
	}


	//entering the coefficients
	cout<<"Now enter the coefficients of the linear recurrence:\n";
	for (int i = 0; i < order; ++i)
	{
		cout<<"c["<<i<<"] = ";
		cin>>coeff[i];
		cout<<endl;
	}

	cout<<"\nHow many elements do you want to print?\n";
	int no_of_elements = 0;
	cin>>no_of_elements;

	
	int k = order;

	for (int i = 0; i < order; ++i)
	{
		cout<<fn[i]<<" ";
	}
	while((no_of_elements>0) and (k<100))
	{
		for (int i = 0; i < order; ++i)
		{
			fn[k]+= ((fn[k-i-1])*(coeff[i])); 
		}
		cout<<fn[k]<<" ";
		++k;
		--no_of_elements;
	}
}