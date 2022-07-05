#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>
#include <string>

using namespace std;

class Tienda {

    char nombre[15];
    char direccionInternet[24];
    char direccionFisica[24];
    char telefono[8];
    vector<Producto *> productos;

    public:
    Tienda();
    Tienda(string nombre, string direccionInternet, string direccionFisica, string telefono);
    ~Tienda();

    void AgregarProducto(Producto *nuevoProducto);

    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStreamBinario(istream *streamEntrada);
    void CargarProductoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionProducto);
    void GenerarArchivoBinario(Tienda *tienda);

    friend ostream& operator << (ostream &o, const Tienda *tienda);

};


#endif