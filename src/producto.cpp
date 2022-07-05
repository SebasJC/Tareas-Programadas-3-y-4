#include "producto.h"
#include <iostream>
#include <cstring>

Producto::Producto(int id, string nombre, int existencias)
{
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    this->existencias = existencias;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombre, "");
    this->existencias = 0;
}

ostream& operator << (ostream &o, const Producto *producto)
{
    o << producto->id << std::endl;
    o << producto->nombre << std::endl;
    o << producto->existencias << std::endl;
}