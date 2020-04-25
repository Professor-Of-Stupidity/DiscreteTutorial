//Program for specifying the principle of inclusion exclusion
//The program will work for upto 3 sets
#include <iostream>
using namespace std;

//defining class set
template <typename T>
class Set
{
private:
	T elements[100];
	int cardinality;
public:
	//constructors
	Set();

	//insertion
	void insert(const T data);

	//deletion
	void delete_element(const T data);

	//to search if element present
	int is_present(const T data) const;

	//getter functions
	int get_cardinality() const;

	//display the set
	void display() const;

	//return the address to the array of elements
	const T* get_elements() const
	{
		const T* ptr = &elements[0];
		return ptr;
	}
};

//now defining fucntions to perform on them

//intersection of 2 sets
template <typename T>
Set<T> intersection_of_sets(const Set<T> &set1,const Set<T> &set2);

//union of 2 sets
template <typename T>
Set<T> union_of_sets(const Set<T> &set1, const Set<T> &set2);

//difference of 2 sets, performs set1-set2
template <typename T>
Set<T> difference(const Set<T> &set1, const Set<T> &set2);

//symmetric differnce
template <typename T>
Set<T> symm_difference(const Set<T> &set1, const Set<T> &set2);

//function to operate the principle on 2 sets
void on_two_sets();

//function to operate the principle on three sets
void on_three_sets();

int main()
{
	int op = 0;
	printf("How many sets do you want to perform the operation (2 or 3)?\nPlease enter: ");
	scanf("%d", &op);
	printf("\n");
	if (op==2)
	{
		on_two_sets();
	}
	else if(op==3)
	{
		on_three_sets();
	}
	else
	{
		printf("Wrong option!\n");
	}
}

template <typename T>
Set<T>::Set()
{
	cardinality = 0;
}

template <typename T>
void Set<T>::insert(const T data)
{
	if (is_present(data)==-1)
	{
		elements[cardinality] = data;
	    ++cardinality;
	}	
}

template <typename T>
void Set<T>::delete_element(const T data)
{
	if(cardinality!=0)
	{
		int index = is_present(data);
		if(index!=-1)
		{
			for(int i = index; i< (cardinality-2); ++i)
			{
				elements[i] = elements[i+1];
			}

			printf("%d successfully deleted from the set\n", data);
		}
		else
		{
			printf("Element %d not present in set!\n", data);
		}
	}

	else
	{
		printf("Set is already empty!\n");
	}
}

template <typename T>
int Set<T>::is_present(const T data) const
{
	for (int i = 0; i < (cardinality); ++i)
	{
		if(elements[i]==data)
		{
			return i;
		}
	}

	return -1;
}

template <typename T>
int Set<T>::get_cardinality() const
{
	return cardinality;
}

template <typename T>
void Set<T>::display() const
{
	if(cardinality==0)
	{
		printf("∅\n");
		return;
	}

	for (int i = 0; i < cardinality; ++i)
	{
		cout<<elements[i]<<" ";
	}
	printf("\n");
}

template <typename T>
Set<T> intersection_of_sets(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr;
	ptr1 = set1.get_elements();

	Set<T> set3;

	int n1 = set1.get_cardinality();
	for (int i = 0; i < n1; ++i)
	{
		if(set2.is_present(ptr1[i])!=-1)
		{
			set3.insert(ptr1[i]);
		}
	}

	return set3;
}

template <typename T>
Set<T> union_of_sets(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	Set<T> set3;

	int n1 = set1.get_cardinality(), n2 = set2.get_cardinality();
	for (int i = 0; i < n1; ++i)
	{
		set3.insert(ptr1[i]);
	}

	for (int i = 0; i < n2; ++i)
	{
		if(set3.is_present(ptr2[i])==-1)
		{
			set3.insert(ptr2[i]);
		}
	}

	return set3;
}

void on_two_sets()
{
	Set<int> set1, set2;
	
	int temp_no = 0;
	printf("Enter the number of elements you want in set 1: \n");
	scanf("%d",&temp_no);
	printf("Enter the elements seperated by space:\n");
	for (int i = 0; i < temp_no; ++i)
	{
		int d = 0; 
		cin>>d;
		set1.insert(d);
	}

	printf("Enter the number of elements you want in set 2: \n");
	scanf("%d",&temp_no);
	printf("Enter the elements seperated by space:\n");
	for (int i = 0; i < temp_no; ++i)
	{
		int d = 0; 
		cin>>d;
		set2.insert(d);
	}

	printf("LHS: n(A ∪ B) = ");
	cout<<(union_of_sets(set1, set2).get_cardinality())<<endl;

	int n_A = set1.get_cardinality();
	int n_B = set2.get_cardinality();
	int n_A_int_B = intersection_of_sets(set1, set2).get_cardinality();
	printf("RHS: n(A)+n(B)-n(A ∩ B) = %d + %d - %d = \n", n_A, n_B, n_A_int_B);
	printf("= %d\n", n_A+n_B-n_A_int_B);
}

void on_three_sets()
{
	Set<int> set1, set2, set3;
	int temp_no = 0;

	printf("Enter the number of elements you want in set 1: \n");
	scanf("%d",&temp_no);
	printf("Enter the elements seperated by space:\n");
	for (int i = 0; i < temp_no; ++i)
	{
		int d = 0; 
		cin>>d;
		set1.insert(d);
	}

	printf("\nEnter the number of elements you want in set 2: \n");
	scanf("%d",&temp_no);
	printf("Enter the elements seperated by space:\n");
	for (int i = 0; i < temp_no; ++i)
	{
		int d = 0; 
		cin>>d;
		set2.insert(d);
	}

	printf("Enter the number of elements you want in set 3: \n");
	scanf("%d",&temp_no);
	printf("Enter the elements seperated by space:\n");
	for (int i = 0; i < temp_no; ++i)
	{
		int d = 0; 
		cin>>d;
		set3.insert(d);
	}

	printf("LHS: n(A ∪ B ∪ C) = ");
	cout<<(union_of_sets(set1, union_of_sets(set2, set3)).get_cardinality())<<endl;

	int n_A = set1.get_cardinality();
	int n_B = set2.get_cardinality();
	int n_C = set3.get_cardinality();
	int n_A_int_B = intersection_of_sets(set1, set2).get_cardinality();
	int n_B_int_C = intersection_of_sets(set2, set3).get_cardinality();
	int n_C_int_A = intersection_of_sets(set3, set1).get_cardinality();
	int n_A_int_B_int_C = intersection_of_sets(set1, intersection_of_sets(set2, set3)).get_cardinality();

	printf("RHS: n(A)+n(B)+n(C)-n(A ∩ B)-n(B ∩ C)-n(C ∩ A)+n(A ∩ B ∩ C) =\n");
	printf("%d + %d + %d - %d - %d - %d + %d\n", n_A, n_B, n_C, n_A_int_B, n_B_int_C, n_C_int_A, n_A_int_B_int_C);
	printf(" = %d", n_A + n_B + n_C - n_A_int_B - n_B_int_C - n_C_int_A + n_A_int_B_int_C);	
}