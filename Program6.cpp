/*input
BA
*/
//Program to generate next combination in lexicographer for a given string
#include <iostream>
#include <string>
using namespace std;

void generate_subsequences(const string in, string out, int i, string* ptr);

//function to calculate 2^n, will be used to calculate the total number of combinations 
int power_2_to_n(int n);

//function to print the next combination of the strings
void print_next_combination(const string str);

//sorts the strings contained in the list of strings lexicographically based on quick-sort
void string_sort(string* &list, int s, int e);
int partition(string* &list, int s, int e);

int main()
{
	string in;
	getline(cin, in);
	
	print_next_combination(in);
	return 0;
}

void print_next_combination(const string str)
{
	int n_comb = power_2_to_n(str.length());
	string* ptr = new string[n_comb];

	generate_subsequences(str, "", 0, ptr);
	string_sort(ptr, 0, n_comb-1);

	for (int i = 0; i < n_comb; ++i)
	{
		if((ptr[i]==str) and (i<n_comb-1) and (ptr[i+1]!=str))
		{
			cout<<ptr[i+1]<<endl;
		}
	    else if((ptr[i]==str) and (i==n_comb-1))
		{
			cout<<"Already the greatest combination lexicographically!"<<endl;
		}
		else
		{
			continue;
		}
	}
}

void generate_subsequences(const string in, string out, int i, string* ptr)
{
	static int count = 0;
	//base case
	if(i==in.length())
	{
		ptr[count] = out;
		count++;
		return;
	}

	//recursive case
	//2. Not including the first character
	generate_subsequences(in, out, i+1, ptr); 

	//1. Including the first character
	out.push_back(in[i]);
	generate_subsequences(in, out, i+1, ptr);
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

int power_2_to_n(int n)
{
	int ans = 1;

	for (int i = 1; i <=n; ++i)
	{
		ans = ans*2;
	}

	return ans;
}