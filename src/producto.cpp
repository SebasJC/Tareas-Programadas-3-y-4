#include "producto.h"
#include <iostream>
#include <cstring>
#include "excepcionDatoEnBlanco.h"
#include "excepcionNumeroNegativo.h"

Producto::Producto(int id, string nombre, int existencias)
{
    this->id = id;

    if(0 > this->id)
    {
        throw ExcepcionNumeroNegativo();
    }

    strcpy(this->nombre, nombre.c_str());

    if(this->nombre == "")
    {
        throw ExcepcionDatoEnBlanco();
    }

    this->existencias = existencias;

    if(0 > this->existencias)
    {
        throw ExcepcionNumeroNegativo();
    }
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