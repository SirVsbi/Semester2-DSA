#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>
#include <assert.h>

using namespace std;


bool r(TComp e1, TComp e2) {
	if (e1 > e2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	testAll();
	testAllExtended();
	
	cout << "Test end" << endl;
	system("pause");
}