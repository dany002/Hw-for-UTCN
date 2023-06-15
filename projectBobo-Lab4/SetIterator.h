#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& s);

	//TODO - Representation

    int currentSlot;   // Current slot index in the set's slots vector
    int currentIndex;  // Current index in the set's hashtable

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


