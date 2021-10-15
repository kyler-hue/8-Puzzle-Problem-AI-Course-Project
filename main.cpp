#include"header.h"
#include"validation.h"
#include"declarations.h"


int main()
{
    std::cout<<"----------- The 8 Puzzle Problem -----------"<<std::endl ;
    std::cout<<"Enter your dimension value of n : "<<std::endl ;
    int n = 0 ;
    std::cin>>n ;
    int arr[n][n] ;
    vector<vector<int>>res ;
    memset(arr,0,sizeof(arr)) ;
    bool valid = true ;
    res = InputPuzzle(n) ;
    change(res,(int*)arr,n) ;

    valid = isSolvable(n,(int*)arr) ;

    if( valid )
    {
        PrintPuzzle(res,n) ;
    }
    else
    {
        std::cout<<endl<<endl<<"\nSorry ! But this puzzle can't be solved with this initial states !!! \nYou can Try again with different positions for your puzzle !!! \n Good Luck !!!"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    }

    return 0 ;
}
