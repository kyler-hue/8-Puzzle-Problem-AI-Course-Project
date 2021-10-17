#include"header.h"
#include"validation.h"
#include"declarations.h"


int main()
{
    std::cout<<"----------- The 8 Puzzle Problem -----------\n\n\n"<<std::endl ;
    std::cout<<"Enter your dimension value of n : "<<std::endl ;
    
    std::cin>>n ;
    int arr[n][n] ;

    memset(arr,0,sizeof(arr)) ;
    bool valid = true ;
    res = InputPuzzle(n) ;
    change(res,(int*)arr,n) ;
    
    valid = isSolvable(n,(int*)arr) ;
    vector<vector<int>>dupliacte(res.begin(),res.end()) ;

    if( valid )
    {
        PrintPuzzle(res,n) ;
        std::cout<<"\t\t\tTo Select The following Heuristic Function , Enter the Corresponding Index Number\n\n\n"<<endl ;
        std::cin>>Choise ;
        switch (Choise)
        {
            case 1://Manhattan Distance.
                

                break;
            case 2:

                
                break;
            case 3:

                
                break;
            case 4:

                
                break;
            case 5:

                
                break;
            default:
                break;
        }

    }
    else
    {
        std::cout<<endl<<endl<<"\nSorry ! But this puzzle can't be solved with this initial states !!! \n\nYou can Try again with different positions for your puzzle !!! \n\n Good Luck !!!"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    }

    return 0 ;
}
