#include "SortedSetIterator.h"
#include <exception>



struct SortedSetIretartorException : public std::exception{
		const char* foo() const throw() {
			return "Function called on invalid iterator";
		}
	};


SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m){
	currentPositon = 0;
}

void SortedSetIterator::first() {
	currentPositon = 0;
}


void SortedSetIterator::next() {
	if(!valid())
		throw SortedSetIretartorException();

	currentPositon++;
}


TElem SortedSetIterator::getCurrent()
{
	if(!(valid()))
		throw SortedSetIretartorException();
	if(currentPositon < multime.numberOfElements){
		return multime.internalArray[currentPositon];
	}
	return NULL_TELEM;
}

bool SortedSetIterator::valid() const {
	if(currentPositon >= multime.numberOfElements)
		return false;
	return true;
}

