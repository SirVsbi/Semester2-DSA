#pragma once
#include "SortedSet.h"
#include <exception>

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
	TElem currentPositon;
	

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;

	//struct SortedSetIretartorException; 
};

