#include <iostream>

bool isSafe(int A[][4],int N, int x, int y){
    if (x<0 || y<0 || x>=N || y>=N)
    {
        return false;
    }
    return true;
}

bool reachable(int A[][4], unsigned N, int sx, int sy,int target){
     if (isSafe(A,N,sx,sy)==true)
     {
        if (A[sx][sy]==target)
        {
            return true;
        }

        bool success = false;

        if( (A[sx][sy]!=0 && isSafe(A,N,sx+1,sy) && A[sx][sy]<A[sx+1][sy]) || 
            (A[sx][sy]!=0 && isSafe(A,N,sx,sy+1) && A[sx][sy]<A[sx][sy+1]) )
        {
            success = reachable(A,N,sx+1,sy,target) || reachable(A,N,sx,sy+1,target);
        }
        
         return success;
     }
     
     return false;
}

int main(){

    int check_matr[][4]={1,0,1,1,
                        10,15,1,1,
                        50,20,50,50,
                        40,0,40,60};

    std::cout << reachable(check_matr,4,0,0,40)<< std::endl; // none
    std::cout << reachable(check_matr,4,0,0,60)<< std::endl; // 1->10->15->20->50->50->60
}