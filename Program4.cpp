/*input
3
1 1 0 
1 1 0
0 0 1
*/
#include <iostream>
using namespace std;

//function to check symmetry in the matrix form of relation
bool is_symmetric(const bool relation_matrix[20][20], const int &cardinality);

//function to check whether the given relation is reflexive or not
bool is_reflexive(const bool relation_matrix[20][20], const int &cardinality);

//function to check whether the given relation is transitive or not
bool is_transitive(const bool relation_matrix[20][20], const int &cardinality);

int main()
{
	//matrix to store the relation in matrix form
	bool relation_matrix[20][20] = {};
	//no of elements in the set on which we are defining the relation
	//because the deifnitions of these relation qualifiers
	//requires that the reltion is defined only on a single set
	int cardinality = 0;

	printf("What is the number of elements in the set on which you have defined the relation R ? \t");
	scanf("%d", &cardinality);

	printf("Enter the matrix notation of the relation :\n");
	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < cardinality ; ++j)
		{
			cin>>relation_matrix[i][j];
		}
	}

	bool symmetry = is_symmetric(relation_matrix, cardinality);
	bool reflexivity = is_symmetric(relation_matrix, cardinality);
	bool transitivity = is_transitive(relation_matrix, cardinality);

	if(symmetry)
	{
		cout<<"R is Symmetric\n";
	}
	else
	{
		cout<<"R is not Symmetric\n";
	}


	if(reflexivity)
	{
		cout<<"R is Reflexive\n";
	}
	else
	{
		cout<<"R is not Reflexive\n";
	}

	if(transitivity)
	{
		cout<<"R is Transitive\n";
	}
	else
	{
		cout<<"R is not Transitive\n";
	}

	if(symmetry and reflexivity and transitivity)
	{
		cout<<"Thus, R is an Equivalence relation\n";
	}
	else
	{
		cout<<"Thus, R is not an Equivalence relation\n";

	}
}

bool is_symmetric(const bool relation_matrix[20][20], const int &cardinality)
{
	//Any relation is symmetric only when the transpose matrix is equal to the relation matrix
	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < cardinality; ++j)
		{
			if(relation_matrix[i][j] != relation_matrix[j][i])
			{
				return false;
			}
		}
	}

	return true;
}

bool is_reflexive(const bool relation_matrix[20][20], const int &cardinality)
{
	//Any relation is reflexive only when all the elements along the diagonal are 1 
	for (int i = 0; i < cardinality; ++i)
	{
		if(relation_matrix[i][i]==0)
		{
			return false;
		}
	}

	return true;
}

bool is_transitive(const bool relation_matrix[20][20], const int &cardinality)
{
	//If a matrix depicting a relation M
	//and Sq_M is the square of matrix M
	//and for each non-zero element in Sq_M, there exists a non zero element in M at the same location
	//then the relation corresponding to M is transitive

	bool sqr_relation_matrix[20][20] = {};
	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < cardinality; ++j)
		{
			sqr_relation_matrix[i][j] = false;
			
			for (int k = 0; k < cardinality; k++)
			{
				sqr_relation_matrix[i][j] += relation_matrix[i][k] * relation_matrix[k][j]; 
			}
		}
	}

	for (int i = 0; i < cardinality; ++i)
	{
		for (int j = 0; j < cardinality; ++j)
		{
			if(((relation_matrix[i][j])==false) and (sqr_relation_matrix[i][j]==true))
			{
				return false;
			}
		}
	}

	return true;
}