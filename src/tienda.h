#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>
#include <string>

using namespace std;

class Tienda {

    char nombre[16];
    char direccionInternet[25];
    char direccionFisica[25];
    char telefono[9];
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