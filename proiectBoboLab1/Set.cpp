#include "Set.h"
#include "SetIterator.h"

Set::Set() {
	//TODO - Implementation
    this->elems = new TElem[1];
    this->capacity = 1;
    this->length = 0;
} //BC=AC=WC=Theta(1)


bool Set::add(TElem elem) {
	//TODO - Implementation
    // Resize
    if(this->capacity == this->length){
        TElem* temporar = new TElem[2*this->capacity];
        for(int i = 0; i < this->length; i++)
            temporar[i] = this->elems[i];
        delete[] this->elems;
        this->capacity *= 2;
        this->elems = temporar;
    }

    for(int i = 0; i < this->length; i++){
        if(this->elems[i] == elem)
            return false;
    }

    this->elems[this->length] = elem;
    this->length++;

	return true;
} // BC=Theta(length)  WC( when capacity == length ) Theta(length) + Theta(length) = 2*Theta(length) = Theta(length)


bool Set::remove(TElem elem) {
	//TODO - Implementation


    for(int i = 0; i < this->length; i++){
        if(this->elems[i] == elem){
            for(int j = i; j < this->length - 1; j++)
                this->elems[j] = this->elems[j+1];
            this->length--;
            return true;
        }
    }
	return false;
} // BC=AC=WC Theta(length)

bool Set::search(TElem elem) const {
	//TODO - Implementation
    for(int i = 0; i < this->length; i++)
        if(this->elems[i] == elem)
            return true;
	return false;
} // BC=AC=WC Theta(length)


int Set::size() const {
	//TODO - Implementation
	return this->length;
} // BC=AC=WC Theta(1)


bool Set::isEmpty() const {
	//TODO - Implementation
    if(this->length == 0)
        return true;
	return false;
} // BC=AC=WC Theta(1)


Set::~Set() {
	//TODO - Implementation
    delete[] this->elems;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


