#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto {

    int id;
    char nombre[21];
    int existencias;

    public:
    Producto(int id, string nombre, int existencias);
    Producto();

    friend ostream& operator << (ostream &o, const Producto *producto);
};

#endif