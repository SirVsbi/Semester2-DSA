#include "Bag.h"
#include "BagIterator.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {
	testAll();
	cout << "Short tests over" << endl;
	testAllExtended();

	cout << "All test over" << endl;
/*

//first testcases

	Bag testBag;
    cout << testBag.isEmpty() << '\n';
	testBag.add(0);
	testBag.add(0);
	testBag.add(0);

	testBag.add(3);

	testBag.add(6);

	testBag.add(6);

	testBag.add(11);
	
	testBag.add(995);
	testBag.add(999);
	testBag.add(947);
	testBag.printBag();

	cout << testBag.size() << '\n';
	cout << testBag.isEmpty() << '\n';
	cout << testBag.search(3) << '\n';
	cout << testBag.search(4) << '\n';
	cout << testBag.nrOccurrences(0) << '\n';
	cout << testBag.nrOccurrences(4) << '\n';

	testBag.remove(6);
	testBag.remove(6);


/*

    testBag.printBag();
    cout << testBag.size() << '\n';
    cout << testBag.isEmpty() << '\n';
    cout << testBag.search(3) << '\n';
    cout << testBag.search(6) << '\n';
    cout << testBag.nrOccurrences(0) << '\n';
    cout << testBag.nrOccurrences(6) << '\n';

    cout << '\n' << '\n';
    BagIterator testBagIterator = testBag.iterator();
    testBagIterator.first();
    cout << testBagIterator.getCurrent() << '\n';

    testBagIterator.next();
    cout << testBagIterator.getCurrent() << '\n';

    testBagIterator.first();
    while(testBagIterator.valid()){
        cout << testBagIterator.getCurrent() << " ";
        testBagIterator.next();
    }
*/

//second testcases
/*
Bag testBag;
for(int i = -100; i < -90; i++){
    testBag.add(i);
    testBag.add(i);
}
  //  testBag.printBag();
for(int i = 0; i < 10; i++)
    testBag.add(i);
testBag.printBag();
}
*/

/*
 //third testcases


 Bag b;
 	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	b.printBag();
*/

/*
  //forth testcase
Bag b;
    for (int i = -5; i < 5; i++) {
        b.add(i);
    }
 //   b.printBag();
    for (int i = -5; i < 5; i++) {
        b.remove(i);
    }
    b.printBag();
*/


//fifth testcase

    Bag b4;
    for (int i = 0; i < 100; i++) {
        b4.add(i);
        b4.add(i * (-2));
        b4.add(i * 2);
        b4.add(i / 2);
        b4.add(i / (-2));
    }
    BagIterator it5 = b4.iterator();
    while (it5.valid()) {
        TElem e = it5.getCurrent();
        it5.next();
        cout << e << '\n';
    }
    b4.printBag();

}

