#include "tienda.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include "excepcionDatoEnBlanco.h"

Tienda::Tienda()
{
    strcpy(this->nombre, "");
    strcpy(this->direccionInternet, "");
    strcpy(this->direccionFisica, "");
    strcpy(this->telefono, "");
}

Tienda::Tienda(string nombre, string direccionInternet, string direccionFisica, string telefono)
{
    strcpy(this->nombre, nombre.c_str());

    if(this->nombre == "")
    {
        throw ExcepcionDatoEnBlanco();
    }

    strcpy(this->direccionInternet, direccionInternet.c_str());

    if(this->direccionInternet == "")
    {
        throw ExcepcionDatoEnBlanco();
    }

    strcpy(this->direccionFisica, direccionFisica.c_str());

    if(this->direccionFisica == "")
    {
        throw ExcepcionDatoEnBlanco();
    }
    
    strcpy(this->telefono, telefono.c_str());

    if(this->telefono == "")
    {
        throw ExcepcionDatoEnBlanco();
    }
}

Tienda::~Tienda()
{
    for (Producto *producto : this->productos)
    {
        delete producto;
    }
}

void Tienda::AgregarProducto(Producto *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::CargarProductoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionProducto)
{
    streamEntrada->seekg(sizeof(Producto) * posicionProducto);

    Producto *producto = new Producto();
    streamEntrada->read((char *)producto, sizeof(Producto));

    this->AgregarProducto(producto);
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);

    streamEntrada->seekg( 0, std::ios::beg ); 
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));

        this->AgregarProducto(producto);
    }
    
}

void Tienda::GenerarArchivoBinario(Tienda *tienda)
{
    ofstream archivoSalida;
    archivoSalida.open("tienda.dat", ios::out|ios::binary);

    if (!archivoSalida.is_open())
    {
        cerr << "No se pudo abrir archivo planilla.dat para escribir los datos";
        return;
    }

    tienda->GuardarEnStreamBinario(&archivoSalida);

    archivoSalida.close();
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << "Tienda: " << std::endl;
    o << tienda->nombre << std::endl;
    o << tienda->direccionInternet << std::endl;
    o << tienda->direccionFisica << std::endl;
    o << tienda->telefono << std::endl;

    o << "Productos: " << std::endl;

    for (Producto *producto : tienda->productos)
    {
        o << producto << endl;
    }
    
    return o;
}