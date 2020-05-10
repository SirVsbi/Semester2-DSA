#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-narrowing-conversions"
#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <math.h>
using namespace std;




int Bag::baseHashFunction(int key) const{
	return abs(key % this->capacity);
}

int Bag::probingFunction(TElem key, int index) const {
	float constant1 = 0.5;
	float constant2 = 0.5;
	return int(abs(this->baseHashFunction(key) + (constant1 * index) + (constant2 * index * index))) % this->capacity;


}


void Bag::resizeInternalArray(){

	//create new internal array with larger size
    this->capacity *= 2;
	TPair* newInternalArray = new TPair[this->capacity];
	for(int i = 0; i < this->capacity; i++){
		newInternalArray[i] = NULL_PAIR;
	}


	//rehash existing elements
	for(int i = 0; i < this->capacity / 2; i++){
		TElem currentElement = this->internalArray[i].first;
		if(currentElement == NULL_TELEM || currentElement == -11112){
            continue;
		}
		int index = 0;
		int position = this->probingFunction(currentElement, index);

		while(index < this->capacity){
			if(newInternalArray[position].first == currentElement){
				break;
			}
			index++;
			position = this->probingFunction(currentElement, index);
		}

		if(index == this->capacity || newInternalArray[position] != NULL_PAIR){
			index = 0;
			position = this->probingFunction(currentElement, 0);
			while(newInternalArray[position] != NULL_PAIR){
				index++;
				position = this->probingFunction(currentElement, index);
			}
			newInternalArray[position].first = currentElement;
			newInternalArray[position].second = this->internalArray[i].second;
		}
		else{
			newInternalArray[position].second++;
		}
	}


	delete[] this->internalArray;
	this->internalArray = newInternalArray;
}



int Bag::internalSearch(TElem elem) const{
	
	int index = 0;
	int position = this->probingFunction(elem, index);
	while(index < this->capacity){
		if(this->internalArray[position].first == elem){
			return position;
		}
		index++;
		position = this->probingFunction(elem, index);
	}

	return -1;
}





Bag::Bag() {
	this->internalArray = new TPair[INITIAL_CAPACITY];
	this->arraySize = 0;
	this->usedBuckets = 0;
	this->capacity = INITIAL_CAPACITY;
	for(int i = 0; i < capacity; i++){
		internalArray[i] = NULL_PAIR;
	}
}


void Bag::add(TElem elem) {

	float loadFactor = (float) this->usedBuckets / (float) this->capacity;
	if(loadFactor >= 0.65){
		this->resizeInternalArray();
	}


	int position = this->internalSearch(elem);

	if(position == -1 ){
		int index = 0;
		position = this->probingFunction(elem, 0);
		while(this->internalArray[position] != NULL_PAIR && this->internalArray[position] != DELETED_TPAIR){
			index++;
			position = this->probingFunction(elem, index);
		}
		this->internalArray[position].first = elem;
		this->internalArray[position].second = 1;
		this->usedBuckets++;
	}
	else{
		this->internalArray[position].second++;
	}

	this->arraySize++;

}


bool Bag::remove(TElem elem) {
	int position = this->internalSearch(elem);
	if(position == -1 || this->internalArray[position] == NULL_PAIR || this->internalArray[position] == DELETED_TPAIR){
	    return false;
	}
	if(this->internalArray[position].second > 1){
	    this->internalArray[position].second--;
	}
	else{
	    this->internalArray[position] = DELETED_TPAIR;
	    this->usedBuckets--;
	}
	this->arraySize--;
	return true;
}


bool Bag::search(TElem elem) const {
    int searchResult = this->internalSearch(elem);
	return searchResult != -1;
}

int Bag::nrOccurrences(TElem elem) const { 
	int searchResult = this->internalSearch(elem);
	if(searchResult == -1){
	    return 0;
	}
	return this->internalArray[searchResult].second;
}


//Complexity: O(1)
int Bag::size() const {
	return this->arraySize;
}

//Complexity: O(1)
bool Bag::isEmpty() const {
	return this->arraySize == 0;
}


BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() = default;


#pragma clang diagnostic pop