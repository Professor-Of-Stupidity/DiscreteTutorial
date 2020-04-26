/*input
7
8 4 1 0 3 5 7
*/
//Check whether a given input is a ring or not
//The ring will be represented as (R, +, *)
//The given set should be an abelian group. The commutative property is preserved for real *, +
//It should satisfy closure property for both the operations
//Both the operations are associative
//The operation * is distributive over +
#include <iostream>
using namespace std;

bool is_Ring(const float set[],const int cardinality);

//function to tell whether the given set is a group or not
//return true when the set is a group
//done
bool is_Group(const float set[],const int cardinality);

//function to check whether closure property is satisfied or not
//done
bool is_closure_satisfied_add(const float set[],const int cardinality);
bool is_closure_satisfied_mul(const float set[],const int cardinality);

//function to find and return the index of identity element of the given set
//returns -1 if the inverse is not present
//1 is the identity element for *, 0 for +
//done
int identity_element(const float set[],const int cardinality);

//function to find the inverse element for the given element
//returns false if no such element exists
//done
bool is_inverse_present(const float set[],const int cardinality,const float element, const float identity_elmnt);

//linear search function to return the index of the search query
//returns -1 if element not present
//done
int is_present(const float set[],const int cardinality, const float key);


int main()
{
	float set[200] = {};
	int cardinality = 0;
	
	cout<<"How many elements do you want to input in the set? Please enter the number: ";
	scanf("%d", &cardinality);
	printf("\n");
	printf("Please enter the elements of your set seperated by a space :\n");
	
	for (int i = 0; i < cardinality; ++i)
	{
		cin>>set[i];
	}

	cout<<endl<<endl;
	bool ans = is_Ring(set, cardinality);
	if (ans)
	{
		cout<<"Yes, it's a Ring!"<<endl;
	}
	else
	{
		cout<<"Hence, its not a Ring"<<endl;
	}
}

bool is_Ring(const float set[],const int cardinality)
{
	if(is_Group(set, cardinality))
	{
		//Now checking whether the given set is a semi group or not
		//We will check for closure over the second operations *
		if(is_closure_satisfied_mul(set, cardinality))
		{
			return true;
		}
		else
		{
			cout<<"Operation * does not follow closure property in the given Set!"<<endl;
			return false;
		}
	}
	else
	{
		cout<<"Set is not a group!"<<endl;
		return false;
	}
}

bool is_Group(const float set[],const int cardinality)
{
	//1. Checking for closure property
	if(is_closure_satisfied_add(set, cardinality))
	{
		//2. Now Checking for identity element
		int identity_elmnt_index = identity_element(set, cardinality);
		if(identity_elmnt_index!=-1)
		{
			//cheking for existence of inverse of every element
			for (int i = 0; i < cardinality; ++i)
			{
				if(is_inverse_present(set, cardinality, set[i], set[identity_elmnt_index])==false)
				{
					cout<<"Inverse for "<<set[i]<<" not present!"<<endl;
					return false;
				}
			}
		}
		else
		{
			cout<<"Identity element does not exist!"<<endl;
			return false;
		}
	}
	else
	{	
		cout<<"Closure Property not satisfied!"<<endl;
		return false;
	}


	//all the properties satisfied
	return true;
}

bool is_closure_satisfied_add(const float set[],const int cardinality)
{
	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < cardinality; ++j)
		{
			float key = (set[i])+(set[j]);
			if(is_present(set, cardinality, key)==-1)
			{
				cout<<key<<" not present to make set a group under (+)!"<<endl;
				return false;
			}
		}
	}

	return true;
}

bool is_closure_satisfied_mul(const float set[],const int cardinality)
{
	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < cardinality; ++j)
		{
			float key = (set[i])*(set[j]);
			if(is_present(set, cardinality, key)==-1)
			{
				cout<<key<<" Not present for closure of *!"<<endl;
				return false;
			}
		}
	}

	return true;
}

int identity_element(const float set[],const int cardinality)
{
	if(is_present(set, cardinality, 0)==-1)
	{
		return false;
	}

	return true;
}

bool is_inverse_present(const float set[],const int cardinality,const float element, const float identity_elmnt)
{
	for (int i = 0; i < cardinality; ++i)
	{
		if(((set[i])+element) == identity_elmnt)
		{
			return true;
		}
	}

	return false;
}

int is_present(const float set[],const int cardinality, const float key)
{
	for (int i = 0; i < cardinality; ++i)
	{
		if((set[i]) == key)
		{
			return i;
		}
	}

	return -1;
}