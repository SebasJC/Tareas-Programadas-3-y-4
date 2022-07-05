#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>
#include "./../src/excepcionDatoEnBlanco.h"

#include "./../src/tienda.h"

using namespace std;

namespace
{
    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("Atlas", "www.atlas.co.cr", "Desamparados, San José", "23452345");

        Producto *producto1 = new Producto(1, "Detergente Clorox", 12);
        tiendaEsperada->AgregarProducto(producto1);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("tienda_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo tienda_test.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Tienda *tiendaLeida = new Tienda();
        tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << tiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaLeida;
        delete tiendaEsperada;

        string esperado = "Tienda: \nAtlas            \nwww.atlas.co.cr           \nDesamparados, San José    \n23452345 \nProductos: \n1   \nDetergente Clorox    \n12  "; 
        string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        // Primero, validar la salida de la planilla esperada sea correcta
        EXPECT_EQ(esperado, salidaTiendaEsperada);

        string salidaTiendaLeidaDeArchivo = streamSalidaTiendaEsperada.str();
        EXPECT_EQ(esperado, salidaTiendaLeidaDeArchivo);
    }

    TEST(Tienda_Test, Test_Nombre_En_Blanco)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("", "www.Atlas.com", "San José", "23432323");

        // Act - ejecute la operación
        EXPECT_THROW({
            Tienda * actual = tienda;
        }, ExcepcionDatoEnBlanco);

        delete tienda;

        // Assert - valide los resultados
    }

    TEST(Tienda_Test, Test_Direccion_Web_En_Blanco)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("Atlas", "", "San José", "23432323");

        // Act - ejecute la operación
        EXPECT_THROW({
            Tienda * actual = tienda;
        }, ExcepcionDatoEnBlanco);

        delete tienda;

        // Assert - valide los resultados
    }

    TEST(Tienda_Test, Test_Direccion_Fisica_En_Blanco)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("Atlas", "www.Atlas.com", "", "23432323");

        // Act - ejecute la operación
        EXPECT_THROW({
            Tienda * actual = tienda;
        }, ExcepcionDatoEnBlanco);

        delete tienda;

        // Assert - valide los resultados
    }

    TEST(Tienda_Test, Test_Telefono_En_Blanco)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tienda = new Tienda("Atlas", "www.Atlas.com", "San José", "");

        // Act - ejecute la operación
        EXPECT_THROW({
            Tienda * actual = tienda;
        }, ExcepcionDatoEnBlanco);

        delete tienda;

        // Assert - valide los resultados
    }
}