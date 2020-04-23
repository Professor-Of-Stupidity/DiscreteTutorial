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

template <typename T>
Set<T> addition_of_sets(const Set<T> &set1, const Set<T> &set2);

template <typename T>
Set<T> subtraction_of_sets(const Set<T> &set1, const Set<T> &set2);

int main()
{
	Set<char> s1;
	Set<char> s2;
	s1.insert('a');
	s1.insert('b');
	s1.insert('c');
	s1.insert('d');
	cout<<"Set 1 : ";
	s1.display();

	s2.insert('b');
	s2.insert('c');
	s2.insert('e');
	cout<<"Set 2 : ";
	s2.display();

	Set<char> s3 = intersection_of_sets(s1, s2);
	s3.display();

	Set<char> s4 = union_of_sets(s1, s2);
	s4.display();

	Set<char> s5 = difference(s1, s2);
	s5.display();

	Set<char> s6 = symm_difference(s1, s2);
	s6.display();

	Set<int> s7;
	s7.insert(1);
	s7.insert(2);
	s7.insert(3);
	

	Set<int> s8;
	s8.insert(7);
	s8.insert(14);
	s8.insert(20);

	Set<int> s9 = addition_of_sets(s8, s7);
	printf("\n");
	s9.display();
	s9 = subtraction_of_sets(s8, s7);
	s9.display();	
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

template <typename T>
Set<T> difference(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr;
	ptr1 = set1.get_elements();
	Set<T> set3;

	int n1 = set1.get_cardinality();

	for (int i = 0; i < n1; ++i)
	{
		if(set2.is_present(ptr1[i])==-1)
		{
			set3.insert(ptr1[i]);
		}
	}

	return set3;
}

template <typename T>
Set<T> symm_difference(const Set<T> &set1, const Set<T> &set2)
{
	Set<T> s1 = difference(set1, set2);
	Set<T> s2 = difference(set2, set1);
	return union_of_sets(s1, s2);
}

template <typename T>
Set<T> addition_of_sets(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	Set<T> set3;

	int n1 = set1.get_cardinality(), n2 = set2.get_cardinality();

	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			T temp = ptr1[i]+ptr2[j];
			set3.insert(temp);
		}
	}

	return set3;
}

template <typename T>
Set<T> subtraction_of_sets(const Set<T> &set1, const Set<T> &set2)
{
	const T*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	Set<T> set3;

	int n1 = set1.get_cardinality(), n2 = set2.get_cardinality();

	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			T temp = ptr1[i]-ptr2[j];
			set3.insert(temp);
		}
	}

	return set3;
}