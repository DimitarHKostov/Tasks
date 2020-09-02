#include <iostream>
#include <stack>

const int labSize = 8;
const int dummyValue = 14;

int lab[labSize][labSize] =    {{0,1,0,1,0,0,0,0},
					{0,1,1,1,0,0,0,0},
					{0,0,1,0,0,0,0,0},
					{1,1,1,0,0,0,0,0},
					{0,1,1,0,0,1,0,0},
					{0,1,1,0,0,1,0,0},
					{0,1,1,0,0,1,0,0},
					{0,1,1,0,0,1,0,0}};

bool validStep(int y, int x){
	return y>=0 && y<labSize && x>=0 && x<labSize && lab[y][x]==0;
}

bool knightMovementRecursive(int lab[labSize][labSize], int sy, int sx, int ey, int ex){
	if(!validStep(sy, sx)){
		return false;
	}
	if(sy==ey && sx==ex){
		return true;
	}
	lab[sy][sx]=dummyValue;
	if(validStep(sy+2,sx+1)){
		if(knightMovementRecursive(lab, sy+2, sx+1, ey, ex)){
			return true;
		}
	}
	if(validStep(sy+2,sx-1)){
		if(knightMovementRecursive(lab, sy+2,sx-1, ey, ex)){
			return true;
		}
	}
	if(validStep(sy+1,sx+2)){
		if(knightMovementRecursive(lab, sy+1,sx+2, ey, ex)){
			return true;
		}
	}
	if(validStep(sy-1,sx+2)){
		if(knightMovementRecursive(lab, sy-1,sx+2, ey, ex)){
			return true;
		}
	}
	if(validStep(sy-2,sx+1)){
		if(knightMovementRecursive(lab, sy-2,sx+1, ey, ex)){
			return true;
		}
	}
	if(validStep(sy-2,sx-1)){
		if(knightMovementRecursive(lab, sy-2,sx-1, ey, ex)){
			return true;
		}
	}
	if(validStep(sy+1,sx-2)){
		if(knightMovementRecursive(lab, sy+1,sx-2, ey, ex)){
			return true;
		}
	}
	if(validStep(sy-1,sx-2)){
		if(knightMovementRecursive(lab, sy-1,sx-2, ey, ex)){
			return true;
		}
	}
	return false;
}
//------------------------------------------
// same but using stack instead of recursion
//------------------------------------------

struct Position{
	int y;
	int x;
};

bool knightMovementIterative(int lab[labSize][labSize], int sy, int sx, int ey, int ex){
	std::stack<Position> s;
	s.push({sy, sx});
	while(!s.empty()){
		Position out = s.top(); s.pop();
		if(out.y==ey && out.x==ex){
			return true;
		}
		if(validStep(out.y, out.x)){
			lab[out.y][out.x]=dummyValue;
			s.push({out.y+2, out.x+1});
			s.push({out.y+2, out.x-1});
			s.push({out.y+1, out.x+2});
			s.push({out.y-1, out.x+2});
			s.push({out.y-2, out.x+1});
			s.push({out.y-2, out.x-1});
			s.push({out.y+1, out.x-2});
			s.push({out.y-1, out.x-2});
		}
	}
	return s.size() > 0;
}

int main(){
	//std::cout << knightMovementRecursive(lab, 0, 0, 7, 7) << std::endl;
	std::cout << knightMovementIterative(lab, 0, 0, 7, 7) << std::endl;
	return 0;
}
