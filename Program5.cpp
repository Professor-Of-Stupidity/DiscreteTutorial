/*input
abcd
*/
#include <iostream>
#include <string>
using namespace std;

//next permutation function returns the string which is next in lexicographical order
//if already the greatest permutation, return an empty string
string next_permutation(string str);

//generates the permutations of the given strings
void generate_permutations(string str, int index, string* &list);

//sorts the strings contained in the list of strings lexicographically based on merge sort
void string_sort(string* &list, int s, int e);

//returns the factorial of given input
//used to calculate total number of possible permutations of the given string
int factorial(int n);

int partition(string* &list, int s, int e);

int main()
{
	string str;
	cin>>str;

	string ans = next_permutation(str);
	cout<<ans<<endl;
}

string next_permutation(string str)
{
	int n = factorial(str.length());
	string* ptr = new string[n];
	generate_permutations(str, 0, ptr);
	string_sort(ptr, 0, n-1);
	
	for (int i = 0; i < n; ++i)
	{
		if((ptr[i]==str) and (i<n-1))
		{
			return ptr[i+1];
		}
	    else if((ptr[i]==str) and (i==n-1))
		{
			return "Already the greatest permutation lexicographically!";
		}
		else
		{
			continue;
		}
	}
	return "";
}

int factorial(int n)
{
	int ans = 1, itr = 1;
	while(itr!=n+1)
	{
		ans = ans * itr;
		++itr;
	}

	return ans;
}

void generate_permutations(string str, int index, string* &list)
{
	static int list_itr= 0;
	static const int n = str.length();
	//base case
	if(index==n)
	{
		list[list_itr] = str;
		++list_itr;
		return;
	}

	//recursive case
	for (int j = index; j < str.length(); ++j)
	{
		swap(str[index], str[j]);
		generate_permutations(str, index+1, list);

		//this step is backtracking, that is, restoring the original array
		swap(str[index], str[j]);
	}
}

void string_sort(string* &list, int s, int e)
{
	//sorting using quicksort algorithm
	//Base case
	if(s>=e)
	{
		return;
	}

	//Recursive Case
	int pivot_index = partition(list, s, e);	//creates 2 partitions in the array about the pivot element
	string_sort(list, s, pivot_index-1);
	string_sort(list, pivot_index+1, e);
}

int partition(string* &list, int s, int e)
{
	string pivot = list[e];
	int i = s-1;
	for (int j = s; j <= e-1; ++j)
	{
		if(list[j]<=pivot)
		{
			++i;
			swap(list[j], list[i]);
		}
	}

	swap(list[i+1], list[e]);
	return i+1;
}
