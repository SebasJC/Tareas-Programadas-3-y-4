#ifndef ExcepcionDatoEnBlanco_H
#define ExcepcionDatoEnBlanco_H

#include <exception>

class ExcepcionDatoEnBlanco : public std::exception
{
    public:
    ExcepcionDatoEnBlanco() noexcept = default;
    ~ExcepcionDatoEnBlanco() = default;

    virtual const char* what() const noexcept {
        return "No se puede dejar datos en blanco.";
    }

};

#endif