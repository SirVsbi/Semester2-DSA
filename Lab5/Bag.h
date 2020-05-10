#pragma once
//DO NOT INCLUDE BAGITERATOR

#include <iostream>
using namespace std;



//DO NOT CHANGE THIS PART
#define NULL_TELEM -11111
typedef int TElem;
class BagIterator;






//this pair containt the unique element, frequency pair 
typedef pair<TElem, TElem> TPair; 

/// The initial capacity is 4, and the capacity of the hash table is 
/// a power of 2 with constants c1 = c2 = 0.5, therefore 
/// the probe sequence will always be a permutation
#define INITIAL_CAPACITY 4


const static pair <TElem, TElem> NULL_PAIR (-11111, -11111);


const static pair <TElem , TElem> DELETED_TPAIR (-11112, -11112);

class Bag {

private:
	//TODO - Representation

	//dynamically allocated array contaning the unique element, frequency pairs
	TPair* internalArray; 

	//the size of the array
	int capacity;


	//the current number of elements in the data structure
	int arraySize; 

	//the number of used slots in the hash table 
	//it's used to calculate the load factor
	int usedBuckets;


	//the base h(k) = k mod m hash function (division method)
    int baseHashFunction(int k) const;

	//The quadratic probing: h(key, i) = (h'(key) + i *(-1)^i) function 
	int probingFunction(TElem k, int i) const;

	//returns the position of a key in the internalArray 
	//Returns the hash of the key, if key is not found
	int internalSearch(TElem elem) const;


	void resizeInternalArray();



	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appears is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	//destructor
	~Bag();


	void printBag(){
		for(int i = 0; i < capacity; i++){
			cout << internalArray[i].first << " " << internalArray[i].second << '\n';
		}
	}
};