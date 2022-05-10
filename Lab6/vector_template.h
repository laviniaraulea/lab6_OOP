#pragma once
#include "erori.h"

template<typename T>
class TemplateVector {

private:

	int cp;
	int dim;
	T* elems;


public:

	int get_lungime() const;

	TemplateVector() noexcept;

	TemplateVector(const TemplateVector& ot);

	void operator=(const TemplateVector& ot);

	~TemplateVector();

	void push_back(const T& newElem);

	void erase(int poz);

	void exchange(int poz1, int poz2);

	int size();

	void resize();

	T& at(const int& poz) const noexcept;

};

template <typename T>
int TemplateVector<T>::get_lungime()const  {
	return dim;
}
template<typename T>
TemplateVector<T>::TemplateVector() noexcept {
	cp = 1;
	dim = 0;
	elems = new T[cp];
}

template<typename T>
TemplateVector<T>::TemplateVector(const TemplateVector& ot) {
	cp = ot.cp;
	dim = ot.dim;
	elems = new T[cp];
	for (int i = 0; i < dim; i++) elems[i] = ot.elems[i];
}

template<typename T>
void TemplateVector<T>::operator=(const TemplateVector& ot) {
	delete[] elems;
	cp = ot.cp;
	dim = ot.dim;
	elems = new T[cp];
	for (int i = 0; i < dim; i++) elems[i] = ot.elems[i];
}

template<typename T>
TemplateVector<T>::~TemplateVector() {
	delete[] elems;
}

template<typename T>
void TemplateVector<T>::resize() {
	T* newElems = new T[2 * cp];
	for (int i = 0; i < cp; i++) {
		newElems[i] = elems[i];
	}
	cp = cp * 2;
	delete[] elems;
	elems = newElems;
}

template<typename T>
void TemplateVector<T>::push_back(const T& newElem) {
	if (dim == cp) resize();
	elems[dim++] = newElem;
}

template<typename T>
int TemplateVector<T>::size() {
	return dim;
}

template<typename T>
T& TemplateVector<T>::at(const int& poz) const noexcept{
	return elems[poz];
}

template<typename T>
void TemplateVector<T>::erase(int poz) {
	if (poz < 0 || poz >= dim) throw Exception("Out of bounds!\n");
	for (int i = poz; i < dim - 1; i++) {elems[i] = elems[i + 1];}
	dim--;
}

template<typename T>
void TemplateVector<T>::exchange(int poz1, int poz2) {
	if (poz1 < 0 || poz1 >= dim) throw Exception("Out of bounds!\n");if (poz2 < 0 || poz2 >= dim) throw Exception("Out of bounds!\n");swap(elems[poz1], elems[poz2]);}

