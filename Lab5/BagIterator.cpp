#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


struct BagIteratorException : public std::exception{
    const char* foo() const throw(){
        return "Function called on invalid operator";
    }

};

BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->currentPosition = 0;
	this->visitedElements = 0;
	this->currentElementCount = 0;
    while(this->bag.internalArray[currentPosition].first == NULL_TELEM)
        currentPosition++;
    currentElementCount = this->bag.internalArray[currentPosition].second;
    visitedElements++;
}

void BagIterator::first() {
    this->currentPosition = 0;
    this->visitedElements = 0;
    this->currentElementCount = 0;
    while(this->bag.internalArray[currentPosition].first == NULL_TELEM)
        currentPosition++;
    currentElementCount = this->bag.internalArray[currentPosition].second;
    visitedElements++;
}


void BagIterator::next() {
    if(!this->valid())
        throw BagIteratorException();

    if(this->currentElementCount != 1){
        this->currentElementCount--;
    }
    else {
        currentPosition++;
        while (this->bag.internalArray[currentPosition].first == NULL_TELEM ||
               this->bag.internalArray[currentPosition].first == -11112) {
            currentPosition++;
            if(currentPosition >= this->bag.capacity){
                break;
            }
        }
        this->currentElementCount = this->bag.internalArray[currentPosition].second;
    }
    visitedElements++;
}


bool BagIterator::valid() const {
    if(this->bag.isEmpty()){
        return false;
    }
    return visitedElements <= this->bag.arraySize;
}



TElem BagIterator::getCurrent() const
{
	if(!this->valid())
	    throw BagIteratorException();
	return this->bag.internalArray[currentPosition].first;
}
