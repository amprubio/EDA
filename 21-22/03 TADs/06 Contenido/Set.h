//  Implementaci�n del TAD Set con array din�mico ordenado y sin repeticiones

#ifndef SET_H
#define SET_H

#include <utility>    // std::move
#include<vector>

template <class T>
class Set {
protected:
    static const int TAM_INICIAL = 10; // tama�o inicial del array din�mico

    // n�mero de elementos del array
    int nelems;

    // tama�o del array
    int capacidad;

    // puntero al array que contiene los elementos ordenados (redimensionable)
    T* array;

public:

    // constructor: conjunto vac�o
    Set() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

    // destructor
    ~Set() {
        libera();
    }

    // constructor por copia
    Set(Set<T> const& other) {
        copia(other);
    }

    // operador de asignaci�n
    Set<T>& operator=(Set<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    bool operator<=(const Set<T>& set) const;

    // A�adir un elemento
    void add(T const& elem) {
        bool found;
        int pos;
        binSearch(elem, found, pos);
        if (!found) {
            shiftRightFrom(pos + 1);
            array[pos + 1] = elem;
            ++nelems;
            if (nelems == capacidad)
                amplia();
        }
    }

    void remove(T const& elem) {
        bool found;
        int pos;
        binSearch(elem, found, pos);
        if (found) {
            shiftLeftFrom(pos);
            --nelems;
        }
    }

    bool contains(T const& x) const {
        bool found;
        int pos;
        binSearch(x, found, pos);
        return found;
    }

    // consultar si el conjunto est� vac�o
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tama�o del array (que no tiene por que ser el tama�o del conjunto en realidad!)
    int size() const {
        return nelems;
    }

    // Devuelve el puntero del array para poder consultar desde fuera su contenido (por ej. para imprimirlo)
    const T* toArray() const {
        return array;
    }


protected:

    void libera() {
        delete[] array;
    }

    // this est� sin inicializar
    void copia(Set const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia() {
        T* viejo = array;
        capacidad *= 2;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }

    void binSearch(const T& x, bool& found, int& pos) const {
        // Pre: los size primeros elementos de array est�n ordenados
        //      size >= 0

        pos = binSearchAux(x, 0, nelems - 1);
        found = (pos >= 0) && (pos < nelems) && (array[pos] == x);

        // Post : devuelve el mayor �ndice i (0 <= i <= nelems-1) que cumple
        //        array[i] <= x
        //        si x es menor que todos los elementos de array, devuelve -1
        //        found es true si x esta en array[0..nelems-1]
    }

    int binSearchAux(const T& x, int a, int b) const {
        // Pre: array est� ordenado entre 0 .. nelems-1
        //      ( 0 <= a <= nelems ) && ( -1 <= b <= nelems ) && ( a <= b+1 )
        //      todos los elementos a la izquierda de 'a' son <= x
        //      todos los elementos a la derecha de 'b' son > x

        int p, m;

        if (a == b + 1)
            p = a - 1;
        else if (a <= b) {
            m = (a + b) / 2;
            if (array[m] <= x)
                p = binSearchAux(x, m + 1, b);
            else
                p = binSearchAux(x, a, m - 1);
        }
        return p;

        // Post: devuelve el mayor �ndice i (0 <= i <= nelems-1) que cumple
        //       array[i] <= x
        //       si x es menor que todos los elementos de array, devuelve -1
    }

    void shiftRightFrom(int i) {
        for (int j = nelems; j > i; j--)
            array[j] = array[j - 1];
    }

    void shiftLeftFrom(int i) {
        for (; i < nelems - 1; i++)
            array[i] = array[i + 1];
    }

};

#endif //SET_H

template<class T>
inline bool Set<T>::operator<=(const Set<T>& set) const
{
    if (empty()) {
        return true;
    }
    else {
        bool jOverI = false;
        int i=0, j=0;
        while (!jOverI && i < size() && size()<set.nelems) {

            if (array[i]>set.array[j]) {
                j++;
            }
            else if (array[i]==array[j]) {
                i++;
                j++;
            }
            else {
                return false;
            }

        }

        if (j >= set.nelems && i < nelems)
            return false;
        else
            return true;

    }
}
