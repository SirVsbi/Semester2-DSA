#include "SortedSet.h"
#include "SortedSetIterator.h"

#include <iostream>
using namespace std;



int binarySearchLeft(int set[], int left, int right, TElem value){
	

	if(right >= left){
		int middle = left + (right - left) / 2;
		if(set[middle] == value){
			return middle;
		}
		if(set[middle] > value){
			return binarySearchLeft(set, left, middle -1 , value);
		}
		return binarySearchLeft(set, middle + 1, right, value);
	}
	return -1;
}	
/*
	for(int i = 0; i < right; i++){
		if(set[i] == value){
			return i;
		}
	}
	return -1;
*/
int binarySearchRight(int set[], int left, int right, TElem value){
	

	if(right >= left){
		int middle = left + (right - left) / 2;
		if(set[middle] == value){
			return middle;
		}
		if(set[middle] < value){
			return binarySearchRight(set, left, middle -1 , value);
		}
		return binarySearchRight(set, middle + 1, right, value);
	}
	return -1;
}	

int binarySearchWrapper(int set[], int left, int right, TElem value, Relation r){
	if(r(1, 2) == true){
		return binarySearchLeft(set, left, right, value);
	}
	else{
		return binarySearchRight(set, left, right, value);
	}

}




SortedSet::SortedSet(Relation r) {
	internalArray = new int[5];
	relation = r;
	arraySize = 5;
	numberOfElements = 0;
}


/*
	Process of adding a new number: 
		1.) Check if the new number is already in the set
			1.a) If number is in the set, return false

*/
bool SortedSet::add(TComp elem) {
	if(numberOfElements == 0){
		internalArray[numberOfElements++] = elem;
		return true;
	}
	if(search(elem)){
		return false;
	}
	else{
		if(numberOfElements >= arraySize - 1){
			TElem *newInternalArray = new int[arraySize * 2];
			for(int i = 0; i < numberOfElements; i++){
				newInternalArray[i] = internalArray[i];
			}
			delete[] internalArray;
			internalArray = newInternalArray;
			arraySize *= 2;
		}
		int i;
		for(i = numberOfElements -1; (i >= 0 && relation(elem, internalArray[i]) == true); i--){
			internalArray[i + 1] = internalArray[i];
		}
		internalArray[i + 1] = elem;
		numberOfElements++;
		return true;
	}
	return false;
}


bool SortedSet::remove(TComp elem) {
	int positon = binarySearchWrapper(internalArray, 0, numberOfElements - 1, elem, relation);
	if(positon == -1){
		return false;
	}
	for(int i = positon; i < numberOfElements - 1; i++){
		internalArray[i] = internalArray[i + 1];
	}
	numberOfElements--;
	return true;
}


bool SortedSet::search(TComp elem) const {

	return binarySearchWrapper(internalArray, 0, numberOfElements - 1, elem, relation) != -1;
}


int SortedSet::size() const {
	return numberOfElements;
}



bool SortedSet::isEmpty() const {
	return numberOfElements == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	delete[] internalArray;
}



