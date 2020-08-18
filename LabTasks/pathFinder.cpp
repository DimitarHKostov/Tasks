#include <iostream>

const int labSize=8;
const int dummyValue=101;

#define Const const int&

bool valid(Const value){
	return value>=0 && value < labSize;
}

bool isPossible(const int matrix[labSize][labSize], Const y, Const x){
	if(valid(y) && valid(x)){
		if(matrix[y][x]==0){
			return true;
		}
	}
	return false;
}

bool hasWay(int matrix[labSize][labSize], Const startY, Const startX, Const endY, Const endX){
	if(!valid(startY) || !valid(startX) || !valid(endY) || !valid(endX) || matrix[startY][startX]!=0){
		return false;
	}

	if(startY==endY && startX==endX){
		return true;
	}

	matrix[startY][startX]=dummyValue;

	if(isPossible(matrix, startY+1, startX)){
		if(hasWay(matrix, startY+1, startX, endY, endX)){
			return true;
		}
	}
	if(isPossible(matrix, startY, startX+1)){
		if(hasWay(matrix, startY, startX+1, endY, endX)){
			return true;
		}
	}
	if(isPossible(matrix, startY-1, startX)){
		if(hasWay(matrix, startY-1, startX, endY, endX)){
			return true;
		}
	}
	if(isPossible(matrix, startY, startX-1)){
		if(hasWay(matrix, startY, startX-1, endY, endX)){
			return true;
		}
	}
	return false;
}

int main(){
	int matrix[8][8]=  {{0,1,0,0,0,1,1,0},
						{0,1,0,1,0,1,1,0},
						{0,1,0,1,0,1,0,0},
						{0,1,0,1,0,1,0,1},
						{0,1,0,1,0,1,0,0},
						{0,1,0,1,0,1,1,0},
						{0,1,0,1,0,1,0,0},
						{0,0,0,1,0,0,0,1}};

	std::cout << hasWay(matrix,0,0,0,7) << std::endl;
	return 0;
}

//-0: safe
//-1: obstacle
//
//  	(y) 	|
//	^ 	|
//	| 	|
//	  	|
//	    	|
// 	   	|
//	 (-y)   |
// 	 | 	|
// 	 v 	|___________________
//    		 <-  (-x)          (x) ->
