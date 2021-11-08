//#include <bits/stdc++.h>
#include"validation.h"

//using namespace std;
//#define N 3

vector<vector<int>>res ;

vector<vector<int>>start ;
vector<vector<int>>goal ;

map<int,pair<int,int>>mpGoal ;
int X , Y , N ;
int Xg , Yg ;
int n ;
char again = 'Y' ;
int arr[200][200] ;
int initial[10][10] ;
int final[10][10] ;
int Choise ;


struct Node
{
    Node* parent;

    int mat[10][10];
    vector<vector<int>>Mat ;

    int x, y;

    int cost;

    int level;
};
void change( ) 
{
	for(int i = 0 ; i < n ; i++ )
	{
		for(int j = 0 ; j < n ; j++ )
		{
			//*( ( arr + i ) + j ) = ans[i][j] ;
			arr[i][j] = res[i][j] ;
            initial[i][j] = res[i][j] ;
            final[i][j] = goal[i][j] ;
			//cout<<arr[i][j]<<"\t" ;
		}
		//cout<<endl;
	}

	
}

void printMatrix(int mat[10][10])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}


Node* newNode(int mat[10][10], int x, int y, int newX,
              int newY, int level, Node* parent)
{
    Node* node = new Node;


    node->parent = parent;


    memcpy(node->mat, mat, sizeof node->mat);


    swap(node->mat[x][y], node->mat[newX][newY]);


    node->cost = INT_MAX;


    node->level = level;

    node->x = newX;
    node->y = newY;

    return node;
}

int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };


int calculateCost(int initial[10][10], int final[10][10])
{
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (initial[i][j] && initial[i][j] != final[i][j])
           count++;
    return count;
}
int CalculateManhattanDistance(int initial[10][10])
{
    int sum = 0 ;

    for( int i = 0 ; i < N ; i++ )
    {
        for( int j = 0 ; j < N ; j++ )
        {
            int xtx = abs(i-mpGoal[ initial[i][j] ].first) ;
            int yty = abs(j-mpGoal[ initial[i][j] ].second) ;

            sum = sum + xtx + yty ;
        }

    }
    return sum ;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}


void printPath(Node* root)
{
    if (root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);

    printf("\n");
}


struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};



void solve( int initial[10][10], int x, int y,int final[10][10] )
{
    
    priority_queue<Node*, std::vector<Node*>, comp> pq;

    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    
    switch (Choise)
    {
        case 1:
            root->cost = CalculateManhattanDistance(initial);
            break;
        case 2:
            root->cost = calculateCost(initial, final);
            break ;
        default:
            break;
    }
    pq.push(root);

    while (!pq.empty())
    {

        Node* min = pq.top();


        pq.pop();


        if (min->cost == 0)
        {

            printPath(min);
            return;
        }


        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {

                Node* child = newNode(min->mat, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->mat, final);


                pq.push(child);
            }
        }
    }
}

/*
int main()
{

    // Value 0 is used for empty space
    int initial[N][N] =
    {
        {1, 2, 3},
        {5, 6, 0},
        {7, 8, 4}
    };

    // Value 0 is used for empty space
    int final[N][N] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    // Blank tile coordinates in initial

    int x = 1, y = 2;

    solve(initial, x, y, final);

    return 0;
}*/

int main()
{
    while( again == 'Y' || again == 'y' )
    {
        std::cout<<"----------- The 8 Puzzle Problem -----------\n\n\n"<<std::endl ;
        std::cout<<"Enter your dimension value of n : "<<std::endl ;
        
        std::cin>>n ;
        N = n ;
        
        
        //memset(arr,0,sizeof(arr)) ;
        bool valid = true ;
        InputPuzzle(n,res,goal,mpGoal,&X,&Y,&Xg,&Yg) ;
        change() ;

        /*

            for(int i =0 ; i < n ; i++ )
            {
                for(int j = 0 ; j < n ; j++ )
                {
                // *( ( arr + i ) + j ) = ans[i][j] ;
                    cout<<arr[i][j]<<"\t" ;
                }
                cout<<endl;
            }

        */
        std::cout<<endl ;
        std::cout<<"\nThe Initial Input Puzzle State Is : \n"<<endl;
        PrintPuzzle(res,n,X,Y) ;
        std::cout<<"\nThe Goal Puzzle State Is : \n"<<endl;
        PrintPuzzle(goal,n,Xg,Yg) ;

        valid = isSolvable(n,(int*)arr) ;
        vector<vector<int>>duplicate(res.begin(),res.end()) ;

        
    
        if( valid )
        {
            
            std::cout<<"\t\t\tTo Select The following Heuristic Function , Enter the Corresponding Index Number\n\n\n"<<endl ;

            std::cout<<"\t1 . Manhattan Distance\n"<<endl ;
            std::cout<<"\t2 . MisPlaced Tiles\n"<<endl ;

            {
                std::cin>>Choise ;
                switch (Choise)
                {
                    case 1://Manhattan Distance.
                    {
                        /*bool manhattan = ManhattanHeuristic() ;
                        if( manhattan )
                        {
                            std::cout<<"\n\nThe Solved Puzzle using Manhattan Distance is : "<<endl<<endl ;
                            std::cout<<"------x-------xx------x------"<<endl;
                            PrintPuzzle(res,n,X,Y) ;
                            std::cout<<"------x-------xx------x------\n\n"<<endl;

                        }
                        else
                        {
                            std::cout<<"Sorry Loops crossed the given limit ,Please Select Other example with lower loops ! try again !!"<<endl<<endl ;
                        }
                    */
                        solve( initial, X , Y , final);
                        break;

                    }
                    case 2 ://no of misplaced tiles
                            solve( initial, X , Y , final);

                            break ;
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
