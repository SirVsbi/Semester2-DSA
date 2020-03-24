#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

#include "ListIterator.h"
#include "IndexedList.h"

using namespace std;

int main(){
    testAll();
    testAllExtended();
    IndexedList testList;
    for(int i = 0; i < 10; i++)
    testList.addToEnd(i);
    ListIterator it = testList.iterator();
    it.first();
    while(it.valid()){
        cout << it.getCurrent() << " ";
        it.next();
    }
    cout << '\n' << testList.removeFromKtoK(2) << '\n';
    it.first();
    while(it.valid()){
        cout << it.getCurrent() << " ";
        it.next();
    }
}