#include <iostream>
#include <algorithm>
#include <vector>

bool* clear(bool* array, int size){
	for(int i = 0; i < size; i++){
		array[i]=false;
	}
	return array;
}

int goat(std::vector<int>& goats, int goatNumber, int crossingTimes){

	int capacity = goats[goatNumber-1];
	int currentCourse = 0;
	int currentWeight = 0;
	int index = goatNumber-1;
	int found = 0;

	bool* used = new bool[goatNumber];
	for(int i = 0; i < goatNumber; i++){
		used[i]=false;
	}

	while(true){
		if(used[index]==false){
			used[index]=true;
			found++;
			currentWeight+=goats[index];

			if(currentWeight < capacity){
				for(int i = index-1; i >= 0; i--){
					if(used[i]==false){
						int bonus = goats[i];
						if(currentWeight + bonus <= capacity){
							currentWeight+=bonus;
							found++;
							used[i]=true;
						}
					}
				}
			}
			currentCourse++;
		}
		
		index--;
		
		currentWeight = 0;

		 if(currentCourse == crossingTimes){
		 	if(found == goatNumber){
		 		break;
		 	}else{
		 		capacity++;
		 		currentCourse = 0;
				index = goatNumber-1;
				clear(used, goatNumber);
				found=0;
		 	}
		 }
	}

	delete[] used;
	return capacity;
}

int main(){
	int n, k;
	int* array = new int[n];
	std::vector<int> goats;
	std::cin >> n >> k;

	for(int i=0; i < n; i++){
		std::cin >> array[i];
		goats.push_back(array[i]);
	}

    std::sort(goats.begin(), goats.end());

    std::cout << goat(goats, n, k) << std::endl;

	delete [] array;
}
