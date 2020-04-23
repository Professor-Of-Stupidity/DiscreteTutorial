#include <iostream>
using namespace std;

template <typename T>
struct element
{
	T data;
	int multiplicity;
};
//defining class MultiSet
template <typename T>
class MultiSet
{
private:
	element<T> elements[100];

	//here cardinality is the number of unique elements in the multiset
	int cardinality;
public:
	//constructors
	MultiSet();
	
	//insertion
	void insert(const T d);
	void insert(const T d, const int mltplcty);

	//to search if element present
	int is_present(const T d) const;

	//getter functions
	int get_cardinality() const;

	//display the set
	void display() const;

	//return the address to the array of elements
	const element<T>* get_elements() const;

	//returns multiplicity of element d
	const int get_multiplicity(const T d) const;
};

//function to take union of 2 multisets
template <typename T>
MultiSet<T> union_of_sets(const MultiSet<T> &set1, const MultiSet<T> &set2);


template <typename T>
MultiSet<T> intersection_of_sets(const MultiSet<T> &set1, const MultiSet<T> &set2);

template <typename T>
MultiSet<T> addition_of_Multisets(const MultiSet<T> &set1, const MultiSet<T> &set2);

template <typename T>
MultiSet<T> difference_of_Multisets(const MultiSet<T> &set1, const MultiSet<T> &set2);

int main()
{
	MultiSet<int> set1, set2, set3;
	set1.insert(1);
	set1.insert(1);
	set1.insert(1);
	set1.insert(3);
	set1.insert(4);
	set1.insert(4);
	set1.display();

	set2.insert(1);
	set2.insert(1);
	set2.insert(3);
	set2.insert(3);
	set2.insert(2);
	set2.display();

	set3 = union_of_sets(set1, set2);
	set3.display();
	set3 = intersection_of_sets(set1, set2);
	set3.display();
	set3 = addition_of_Multisets(set1, set2);
	set3.display();
	set3 = difference_of_Multisets(set1, set2);
	set3.display();
}

template <typename T>
MultiSet<T>::MultiSet()
{
	for (int i = 0; i < 100; ++i)
	{
		elements[i].data = 0;
		elements[i].multiplicity=0;
	}

	cardinality = 0;
}

template <typename T>
void MultiSet<T>::insert(const T d)
{

	int index = is_present(d);
	if(index==-1)
	{
		elements[cardinality].data = d;
		elements[cardinality].multiplicity=1;
		++cardinality;
	}
	else
	{
		++elements[index].multiplicity;
	}
}

template <typename T>
void MultiSet<T>::insert(const T d, const int mltplcty)
{
	if(mltplcty==0)
	{
		return;
	}

	int index = is_present(d);
	if(index==-1)
	{
		elements[cardinality].data = d;
		elements[cardinality].multiplicity = mltplcty;
		++cardinality;
	}
	else
	{
		elements[index].multiplicity+= mltplcty;
	}
}

template <typename T>
int MultiSet<T>::is_present(const T d) const
{
	for (int i = 0; i < (cardinality); ++i)
	{
		if(elements[i].data==d)
		{
			return i;
		}
	}

	return -1;
}

template <typename T>
const element<T>* MultiSet<T>::get_elements() const
{
	const element<T>* ptr = elements;
	return ptr;
}

template <typename T>
const int MultiSet<T>::get_multiplicity(const T d) const
{
	int index = is_present(d);
	if(index==-1)
	{
		return 0;
	}
	else
	{
		return elements[index].multiplicity;
	}
}

template <typename T>
void MultiSet<T>::display() const
{
	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < elements[i].multiplicity; ++j)
		{
			cout<<elements[i].data<<" ";
		}
	}
	printf("\n");
}

template<typename T>
int MultiSet<T>::get_cardinality() const
{
	return cardinality;
}

template <typename T>
MultiSet<T> union_of_sets(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	MultiSet<T> set3;

	int n1 = set1.get_cardinality(), n2 = set2.get_cardinality();

	//iterating over the set1
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= max(ptr1[i].multiplicity, set2.get_multiplicity(ptr1[i].data));
		set3.insert(ptr1[i].data, temp_mult);	
	}

	//iterating over set 2 and inserting elements which were not already present
	for (int i = 0; i < n2; ++i)
	{
		if(set3.is_present(ptr2[i].data)==-1)
		{
			set3.insert(ptr2[i].data, ptr2[i].multiplicity);
		}

	}

	return set3;
}

template <typename T>
MultiSet<T> intersection_of_sets(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	MultiSet<T> set3;

	int n1 = set1.get_cardinality();
	//iterating over the set1
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= min(ptr1[i].multiplicity, set2.get_multiplicity(ptr1[i].data));
		set3.insert(ptr1[i].data, temp_mult);	
	}

	return set3;
}

template <typename T>
MultiSet<T> addition_of_Multisets(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	MultiSet<T> set3;

	int n1 = set1.get_cardinality(), n2 = set2.get_cardinality();

	//iterating over the set1
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= ptr1[i].multiplicity + set2.get_multiplicity(ptr1[i].data);
		set3.insert(ptr1[i].data, temp_mult);	
	}

	for (int i = 0; i < n2; ++i)
	{
		if(set3.is_present(ptr2[i].data)==-1)
		{
			set3.insert(ptr2[i].data, ptr2[i].multiplicity);
		}

	}

	return set3;
}

template <typename T>
MultiSet<T> difference_of_Multisets(const MultiSet<T> &set1, const MultiSet<T> &set2)
{
	const element<T>*ptr1 =nullptr, *ptr2 = nullptr;
	ptr1 = set1.get_elements();
	ptr2 = set2.get_elements();

	MultiSet<T> set3;

	int n1 = set1.get_cardinality(), n2 = set2.get_cardinality();

	//iterating over the set1
	for (int i = 0; i < n1; ++i)
	{
		int temp_mult= max((ptr1[i].multiplicity-set2.get_multiplicity(ptr1[i].data)), 0);
		set3.insert(ptr1[i].data, temp_mult);
	}

	return set3;
}