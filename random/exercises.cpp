#include <iostream>
#include <utility>
#include <stack>
#include <unordered_map>

double HN_recursive(int n, double x){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 2 * x;
	}
	return 2 * x * HN_recursive(n-1, x) + 2 * (n - 1) * HN_recursive(n-2, x);
}

struct HnStackData{
	int n;
	int x;
	bool areChildrenCalculated;
};

double HN_stack(int n, int x){
	std::unordered_map<int, int> results;
	std::stack<HnStackData> stack;
	results[0]=1;
	results[1]=2*x;
	if(n<=1){
		return results[n];
	}
	stack.push({n,x,false});

	while(!stack.empty()){
		HnStackData gettingOut = stack.top();
		stack.pop();
		if(results.count(gettingOut.n)==1){
			continue;
		}
		if(gettingOut.areChildrenCalculated){
			results[gettingOut.n] = 2 * x * results[gettingOut.n - 1] + 2 * (gettingOut.n - 1) * results[gettingOut.n - 2];
		}else{
			stack.push({gettingOut.n, x, true});
			stack.push({gettingOut.n - 1, x, false});
			stack.push({gettingOut.n - 2, x, false});
		}
	}
	return results[n];
}

struct FibData{
	int n;
	bool flag;
};

int calcNFibStack(int n){
	std::unordered_map<int, int> results;
	results[0]=1;
	results[1]=1;
	if(n<=1){
		return results[n];
	}
	std::stack<FibData> stack;
	stack.push({n, false});
	while(!stack.empty()){
		FibData out = stack.top();
		stack.pop();
		if(results.count(out.n)==1){
			continue;
		}
		if(out.flag){
			results[out.n] = results[out.n - 1] + results[out.n - 2];
		}else{
			stack.push({out.n, true});
			stack.push({out.n-1, false});
			stack.push({out.n-2,false});
		}
	}
	return results[n];
}

const int labsize = 8;
const int dummyValue = 7;

int lab[labsize][labsize] ={{0,1,0,0,0,1,1,0},
							{0,1,0,1,0,1,1,0},
							{0,1,0,1,0,1,0,0},
							{0,1,0,1,0,1,0,1},
							{0,1,0,1,0,1,0,0},
							{0,1,0,1,0,1,1,0},
							{0,1,0,1,0,1,0,0},
							{0,0,0,1,0,0,0,1}};

bool validPosition(int y, int x){
	return y>=0 && x>=0 && y<labsize && x<labsize && lab[y][x]==0; 
}

bool hasWayRecursive(int lab[labsize][labsize], int sy, int sx, int ey, int ex){
	if(!validPosition(sy, sx)){
		return false;
	}

	if(sy==ey && sx==ex){
		return true;
	}

	lab[sy][sx]=dummyValue;

	if(validPosition(sy+1, sx)){
		if(hasWayRecursive(lab, sy+1, sx, ey, ex)){
			return true;
		}
	}

	if(validPosition(sy, sx+1)){
		if(hasWayRecursive(lab, sy, sx+1, ey, ex)){
			return true;
		}
	}

	if(validPosition(sy-1, sx)){
		if(hasWayRecursive(lab, sy-1, sx, ey, ex)){
			return true;
		}
	}

	if(validPosition(sy, sx-1)){
		if(hasWayRecursive(lab, sy, sx-1, ey, ex)){
			return true;
		}
	}

	return false;
}

struct Pair{
	int y;
	int x;
};

bool hasWayIterative(int lab[labsize][labsize], int sy, int sx, int ey, int ex){
	std::stack<Pair> s;
	s.push({sy, sx});

	while(s.size() != 0 && !s.top().y==ey && s.top().x==ex){
		Pair crr = s.top(); s.pop();
		if(validPosition(crr.y, crr.x)){
			lab[crr.y][crr.x]=dummyValue;
			s.push ({crr.y+1, crr.x});
            s.push ({crr.y, crr.x+1});
            s.push ({crr.y-1,crr.x});
            s.push ({crr.y,crr.x-1});
		}
	}
	return s.size() > 0;
};



int main(){
	//std::cout << HN_stack(8, 2) << std::endl;
	//std::cout << HN_recursive(8, 2) << std::endl;
	//std::cout << calcNFibStack(5) << std::endl;
	//std::cout << hasWayRecursive(lab,0,0,0,7) << std::endl;
	//std::cout << hasWayIterative(lab,0,0,0,7) << std::endl;
	return 0;
}