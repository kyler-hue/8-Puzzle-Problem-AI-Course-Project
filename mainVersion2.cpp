#include"header.h"
#include"validation.h"

//Function Declarations


int getInvCount(int arr[] , int N );
int findXPosition(int* puzzle ) ;
bool isSolvable( int N , int* puzzle );
void PrintPuzzle(vector<vector<int>>res , int N,int x ,int y) ;
void change() ;
bool CheckSolved(int N) ;
bool ManhattanHeuristic(vector<vector<int>>res, int N ,vector<vector<int>>goal,map<int,pair<int,int>>mpGoal );
int CalculateManhattanDistance(vector<vector<int>>res, int N ,vector<vector<int>>goal,map<int,pair<int,int>>mpGoal );
pair<int,int> Evaluate( vector<vector<int>>res,int N ,vector<vector<int>>goal,map<int,pair<int,int>>mpGoal );

//vector<vector<int>> InputPuzzle(int N,int x,int y ) ;




vector<vector<int>>res ;
vector<vector<int>>goal ;

map<int,pair<int,int>>mpGoal ;
int X , Y , N ;
int Xg , Yg ;
int n ;
char again = 'Y' ;
int row[4] = {1,-1,0,0} ;
int col[4] = {0,0,1,-1} ;
int arr[200][200] ;
pair<int,int>LastMove ;

int main()
{
    while( again == 'Y' || again == 'y' )
    {
        std::cout<<"----------- The 8 Puzzle Problem -----------\n\n\n"<<std::endl ;
        std::cout<<"Enter your dimension value of n : "<<std::endl ;
        
        std::cin>>n ;
        N = n ;
        int Choise ;

        memset(arr,0,sizeof(arr)) ;
        bool valid = true ;
        InputPuzzle(n,res,goal,mpGoal,&X,&Y,&Xg,&Yg) ;
        change() ;

        for(int i =0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < n ; j++ )
            {
               // *( ( arr + i ) + j ) = ans[i][j] ;
                cout<<arr[i][j]<<"\t" ;
            }
            cout<<endl;
        }
        cout<<endl ;
        PrintPuzzle(res,n,X,Y) ;
        cout<<endl ;
        PrintPuzzle(goal,n,Xg,Yg) ;

        valid = isSolvable(n,(int*)arr) ;
        vector<vector<int>>duplicate(res.begin(),res.end()) ;

        
    
        if( valid )
        {
            PrintPuzzle(res,n,X,Y) ;
            PrintPuzzle(goal,n,Xg,Yg) ;
            std::cout<<"\t\t\tTo Select The following Heuristic Function , Enter the Corresponding Index Number\n\n\n"<<endl ;

            std::cout<<"\t1 . Manhattan Distance\n"<<endl ;
            std::cout<<"\t2 . Manhattan Distance\n"<<endl ;



            
            {
                std::cin>>Choise ;
                switch (Choise)
                {
                    case 1://Manhattan Distance.
                    {
                        bool manhattan = ManhattanHeuristic() ;
                        if( manhattan )
                        {
                            std::cout<<"The Solved Puzzle using Manhattan Distance is : "<<endl<<endl ;
                            PrintPuzzle(res,n,X,Y) ;

                        }
                        else
                        {
                            std::cout<<"Some error occured ! try again !!"<<endl<<endl ;
                        }

                        break;

                    }
                    default:
                        break;
                }

                
                std::cout<<"If you want to play again , Enter Y else N"<<endl<<endl ;
                std::cin>>again ;
                if( again == 'Y' || again == 'y' )
                    continue ;
                else if( again == 'N' || again == 'n' )
                    break;

            }

        }
        else
        {
            std::cout<<endl<<endl<<"\nSorry ! But this puzzle can't be solved with this initial states !!! \n\nYou can Try again with different positions for your puzzle !!! \n\n Good Luck !!!"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            std::cout<<"If you want to play again , Enter Y else N"<<endl<<endl ;
                std::cin>>again ;
                if( again == 'Y' || again == 'y' )
                    continue ;
                else if( again == 'N' || again == 'n' )
                    break;


        }
    }
    return 0 ;
}

//change vector to array 
void change( ) 
{
	for(int i =0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < n ; j++ )
		{
			//*( ( arr + i ) + j ) = ans[i][j] ;
			arr[i][j] = res[i][j] ;
			//cout<<arr[i][j]<<"\t" ;
		}
		//cout<<endl;
	}

	
}

bool CheckSolved( )
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if( res[i][j] != goal[i][j] )
                return false ;
        }
    }
    return true ;
        
}
int CalculateManhattanDistance()
{
    int sum = 0 ;

    for( int i = 0 ; i < N ; i++ )
    {
        for( int j = 0 ; j < N ; j++ )
        {
            int xtx = abs(i-mpGoal[ res[i][j] ].first) ;
            int yty = abs(j-mpGoal[ res[i][j] ].second) ;

            sum = sum + xtx + yty ;
        }

    }
    return sum ;
}

pair<int,int> Evaluate( )
{
    int mx = INT_MAX ;
    for(int i=0;i<4;i++)
    {   
        //Check for the adjacent positions and swap the numbers 
        if( abs(row[i]+X) >= 0 && abs(row[i]+X) < N && abs(col[i]+Y) >= 0 && abs(col[i]+Y) < N && LastMove.first != abs(row[i]+X) && LastMove.second != abs(col[i]+Y))
        {
            int lt = abs(row[i]+X) ;
            int rt = abs(col[i]+Y) ;
            swap( res[X][Y] , res[lt][rt] ) ;
            /*int tmp2 = res[X][Y] ;
            res[X][Y] = res[row[i]+X][col[i]+Y] ;
            res[row[i]+X][col[i]+Y] = tmp2 ;
            */
            int tmp = CalculateManhattanDistance(  ) ;
            cout<<"\n"<<tmp<<"  SUM  "<< lt <<" "<< rt <<endl ;
            if( tmp <= mx )
            {
                alter.first = row[i]+X ;
                alter.second = col[i]+Y  ;
                mx = tmp ;
            }
            //undo the steps
            swap( res[X][Y] , res[row[i]+X][col[i]+Y] ) ;
           /* tmp2 = res[X][Y] ;
            res[X][Y] = res[row[i]+X][col[i]+Y] ;
            res[row[i]+X][col[i]+Y] = tmp2 ;
            */
        }

    }
    return alter ;
}

bool ManhattanHeuristic( )
{
	pair<int,int>tom ;
    int Solved = false ;
    int count = 30 ;

    //So the loop will run only upto 100 iterations.
    while( !Solved  )
    {
        if(!count)
            break;
        count--;
        Solved = CheckSolved() ;
        if(Solved)
            return true ;
        
        tom = Evaluate() ;
        
        //swap the corresponding elements and space
        swap( res[tom.first][tom.second] , res[X][Y] ) ;
        /*
        int tmp2 = res[X][Y] ;
        res[X][Y] =  res[tom.first][tom.second] ;
        res[tom.first][tom.second] = tmp2 ;
        */
        LastMove.first = X ;
        LastMove.second = Y ;

        X = tom.first ;
        Y = tom.second ;
        
        cout<<" "<<X<<"  "<<Y<<endl ;
        cout<<"================"<<endl;
    }

    return false ;

}