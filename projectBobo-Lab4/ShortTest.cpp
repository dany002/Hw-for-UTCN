#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"
#include <iostream>
using namespace std;

void testAll() {
    cout << "HI";

    Set s;
    cout << "HI";

    assert(s.isEmpty() == true);
    cout << "HI";

    assert(s.size() == 0);
    cout << "HI";

    assert(s.add(5)==true);
    cout << "HI";

    assert(s.add(1)==true);
    cout << "HI";
    assert(s.add(10)==true);
    cout << "HI";
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);

    cout << "HI";

    assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
    cout << "HI";

    assert(s.remove(1) == true);
	/*
    assert(s.remove(6) == false);
	assert(s.size() == 4);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);
    */
}

