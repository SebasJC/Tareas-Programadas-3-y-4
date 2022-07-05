#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>
#include "./../src/excepcionDatoEnBlanco.h"
#include "./../src/excepcionNumeroNegativo.h"

#include "./../src/producto.h"

using namespace std;

namespace
{

    TEST(Producto_Test, Test_Id_Negativa)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(-1, "Detergente Clorox", 21);

        // Act - ejecute la operación
        EXPECT_THROW({
            Producto * actual = producto;
        }, ExcepcionNumeroNegativo);

        delete producto;

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Nombre_En_Blanco)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "", 21);

        // Act - ejecute la operación
        EXPECT_THROW({
            Producto * actual = producto;
        }, ExcepcionDatoEnBlanco);

        delete producto;

        // Assert - valide los resultados
    }

    TEST(Producto_Test, Test_Existencia_Negativa)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto = new Producto(1, "Detergente Clorox", -21);

        // Act - ejecute la operación
        EXPECT_THROW({
            Producto * actual = producto;
        }, ExcepcionNumeroNegativo);

        delete producto;

        // Assert - valide los resultados
    }

}