#include "SetIterator.h"
#include "Set.h"
#include <exception>

SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
    this->current = 0;
} //BC=AC=WC Theta(1)


void SetIterator::first() {
	//TODO - Implementation
    this->current = 0;
} //BC=AC=WC Theta(1)


void SetIterator::next() {
	//TODO - Implementation
    if(this->current >= this->set.length)
        throw std::exception();
    this->current++;
} //BC=AC=WC Theta(1)


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
    if(this->current >= this->set.length)
        throw std::exception();
    return this->set.elems[this->current];

} // BC=AC=WC Theta(1)

bool SetIterator::valid() const {
	//TODO - Implementation
    if(this->current < this->set.length)
        return true;
    return false;
} // BC=AC=WC Theta(1)

void SetIterator::jumpBackward(int k) {
    if(!this->valid())
        throw std::exception();
    if(this->current - k < 0 || k <= 0)
        throw std::exception();
    this->current -= k;
} // BC=AC=WC Theta(1)



