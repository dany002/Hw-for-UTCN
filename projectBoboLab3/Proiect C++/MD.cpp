#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;


MD::MD() {
	/* de adaugat */
    this->cap = NULL;
}


void MD::adauga(TCheie c, TValoare v) {
	/* de adaugat */
    this->cap = new MD::nod(c,v, this->cap);
}


bool MD::sterge(TCheie c, TValoare v) {
	/* de adaugat */
    if(this->cap == NULL) {
        return false;
    }

    if(this->cap->cheie == c && this->cap->valoare == v) {
        MD::nod* urmatorul_cap = this->cap->urmatorul;
        delete this->cap;
        this->cap = urmatorul_cap;
        return true;
    }

    for(MD::nod* curent = this->cap; curent->urmatorul != NULL; curent = curent->urmatorul) {
        if(curent->urmatorul->cheie == c && curent->urmatorul->valoare == v) {
            MD::nod* real_next = curent->urmatorul->urmatorul;
            delete curent->urmatorul;
            curent->urmatorul = real_next;
            return true;
        }
    }

    return  false;
}


vector<TValoare> MD::cauta(TCheie c) const {
	/* de adaugat */
    vector<TValoare> v = vector<TValoare>();
    for (MD::nod* curent = this->cap; curent != NULL; curent = curent->urmatorul) {
        if (curent->cheie == c)
            v.push_back(curent->valoare);
    }
    return v;
}


int MD::dim() const {
	/* de adaugat */
    int i = 0;
    for (MD::nod* curent = this->cap; curent != NULL; curent = curent->urmatorul) {
        i++;
    }
	return i;
}


bool MD::vid() const {
	/* de adaugat */
    if (this->dim() == 0)
        return true;
	return false;
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}


void MD::dealocare(MD::nod *curent) {
    if(curent == NULL) {
        return ;
    }

    this->dealocare(curent->urmatorul);
    delete curent;

}

MD::~MD() {
	/* de adaugat */
    this->dealocare(this->cap);
}



