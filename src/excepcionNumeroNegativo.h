#ifndef ExcepcionNumeroNegativo_H
#define ExcepcionNumeroNegativo_H

#include <exception>

class ExcepcionNumeroNegativo : public std::exception
{
    public:
    ExcepcionNumeroNegativo() noexcept = default;
    ~ExcepcionNumeroNegativo() = default;

    virtual const char* what() const noexcept {
        return "No se pueden utilizar números negativos.";
    }

};

#endif