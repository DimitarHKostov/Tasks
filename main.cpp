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
	bool foundSolution = false;

	while(true){
		if(currentCourse < crossingTimes){
			if(used[index]==false){
				used[index]=true;
				currentWeight+=goats[index];
				found++;
				for(int i = 0; i < goatNumber-found; i++){
					if(currentWeight < capacity && used[i]==false){
						used[i]=true;
						int bonus = goats[i];
						if(currentWeight + bonus <= capacity){
							currentWeight+=bonus;
							found++;
						}
					}
				}
			}

			if(found == goatNumber){
				foundSolution=true;
			}
			index--;
		}

		currentCourse++;
		currentWeight = 0;

		if(currentCourse >= crossingTimes && !foundSolution){
			capacity++;
			index = goatNumber-1;
			clear(used, goatNumber);
			found=0;
		}

		if(currentCourse >= crossingTimes && foundSolution){
			break;
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