#include "IteratorMD.h"
#include "MD.h"
#include <stdlib.h>

using namespace std;

IteratorMD::IteratorMD(const MD& _md): md(_md) {
	/* de adaugat */
    this->curent = _md.cap;
}

TElem IteratorMD::element() const{
	/* de adaugat */
    if(this->curent == NULL) {
        throw exception();
    }
    return make_pair(this->curent->cheie, this->curent->valoare);
}

bool IteratorMD::valid() const {
	/* de adaugat */
    if(this->curent == NULL)
	    return false;
    return true;
}

void IteratorMD::urmator() {
	/* de adaugat */
    if(!this->valid())
        throw exception();
    this->curent = this->curent->urmatorul;
}

void IteratorMD::prim() {
	/* de adaugat */
    this->curent = md.cap;
}

