#include"header.h"
#include"declarations.h" 
int X , Y ;

int getInvCount(int arr[],int N )
{
	int inv_count = 0 ;
	for (int i = 0; i < N * N - 1; i++)
	{
		for (int j = i + 1; j < N * N; j++)
		{
			// count pairs(i, j) such that i appears
			// before j, but i > j.
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
		}
	}
	return inv_count;
}

// find Position of blank from bottom
int findXPosition(int* puzzle,int N)
{

	// start from bottom-right corner of matrix
	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j >= 0; j--)
			if ( *((puzzle+i)+j) == 0 )
				return N - i;
	return 0;
}

// This function returns true if given
// instance of N*N - 1 puzzle is solvable
bool isSolvable(int N ,int* puzzle )
{
	// Count inversions in given puzzle
	int invCount = getInvCount((int*)puzzle,N);
    
	// If grid is odd, return true if inversion
	// count is even.
	if (N & 1)
		return !(invCount & 1);

	else	 // grid is even
	{
		int pos = findXPosition( puzzle , N );
		if (pos & 1)
			return !(invCount & 1);
		else
			return invCount & 1;
	}
}

vector<vector<int>> InputPuzzle( int N )
{

	std::cout<<"Enter the co-ordinates of the space\n" <<endl ;
	std::cin>>X>>Y ;
	std::cout<<"Enter your numbers in the puzzle"<<std::endl<<std::endl ;
	vector<int>vt ;
	vector<vector<int>>res ;
	int tmp = 0 ;

	for( int i = 0 ; i < N ; i++ )
	{
		for( int j = 0 ; j < N ; j++ )
		{
			cin>>tmp ;
			vt.push_back(tmp) ;
		}
		res.push_back(vt) ;
		vt.clear() ;
		
	}
	
	return res ;

}

//This function print's the NxN matrix
void PrintPuzzle(vector<vector<int>>res , int N )
{
	int t = N ;
	std::cout<<std::endl<<std::endl ;


	for(int i = 0 ;i < N ; i++ )
	{
		std::cout<<"| " ;
		for( int j = 0 ; j < N ; j++  )
		{
			if( i == X && j == Y )
			{
				std::cout<<"_"<<" |"<<" " ;
			}
			else
				std::cout<<res[i][j]<<" |"<<" " ;
		}

		std::cout<<std::endl ;
	}
	std::cout<<std::endl<<std::endl ;
	
}
//change vector to array 
void change(vector<vector<int>>&ans , int* arr , int N) 
{
	for(int i =0 ; i < N ; i++ )
		for(int j = 0 ; j < N ; j++ )
			*( ( arr + i ) + j ) = ans[i][j] ;

	
}

//Manhattan Distance Heuristic 

void ManhattanHeuristic( vector<vector<int>>&ans , int N )
{

}
