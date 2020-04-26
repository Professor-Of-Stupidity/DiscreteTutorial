/*input
20
1 2 3 4 5 6 8 10 12 15
240 120 80 60 48 40 30 24 20 16
*/
//Program to check whether a given divisibility poset is a lattice or not
//This program will check for lattice using the logic that
//each element is comparable to the maximal element (if it exists) and 
//the minimal element (if it exists) is comparable to all the elements in the set
//Given a poset under divisibility
#include <iostream>
using namespace std;

//bool function to return true if the given poset is a lattice
bool is_lattice(const int poset[], const int cardinality);

//a function to tell whether a given element is the maximal element or not
bool is_element_maximal(const int poset[], const int cardinality, const int max_element);

//a function to tell whether a given element is the minimmal element or not
bool is_element_minimal(const int poset[], const int cardinality, const int min_element);

int main()
{
	int poset[200]={};
	printf("\nEnter the number of elements in the poset: ");
	int cardinality = 0;
	scanf("%d", &cardinality);
	printf("\nPlease enter the elements present in poset: \n");


	for (int i = 0; i < cardinality; ++i)
	{
		scanf("%d", &poset[i]);
	}

	bool ans = is_lattice(poset, cardinality);
	if(ans)
	{
		cout<<"\nYes, the given poset is a lattice\n";
	}
	else
	{
		cout<<"\nNo, the given poset is not a lattice\n";
	}

	return 0;
}

bool is_lattice(const int poset[], const int cardinality)
{
	//to find the maximum element in the set
	int max_element = poset[0];
	for (int i = 1; i < cardinality; ++i)
	{
		if(poset[i]>max_element)
		{
			max_element = poset[i];
		}
	}

	//returns true if the maximum element is the maximal element of the poset
	bool ans1 = is_element_maximal(poset, cardinality, max_element);

	//to find the element if set having the minimum value
	int min_element = poset[0];
	for (int i = 1; i < cardinality; ++i)
	{
		if (poset[i]<min_element)
		{
			min_element = poset[i];
		}
	}

	//returns true if element with minimum value is the minimal element of the poset
	bool ans2 = is_element_minimal(poset, cardinality, min_element);

	return (ans1 and ans2);
}

bool is_element_maximal(const int poset[], const int cardinality, const int max_element)
{
	for (int i = 0; i < cardinality; ++i)
	{
		if((max_element%poset[i])!=0)
		{
			return false;
		}
	}

	return true;
}

bool is_element_minimal(const int poset[], const int cardinality, const int min_element)
{
	for (int i = 0; i < cardinality; ++i)
	{
		if((poset[i]%min_element)!=0)
		{
			return false;
		}
	}

	return true;	
}