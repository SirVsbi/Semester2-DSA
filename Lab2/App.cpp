#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

#include "ListIterator.h"
#include "IndexedList.h"

using namespace std;

int main(){
    testAll();
    testAllExtended();
    cout<<"Finished LI Tests!"<<endl;
}