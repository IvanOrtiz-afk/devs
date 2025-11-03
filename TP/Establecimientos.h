#pragma once
#include <string>

class Establecimientos
{
    public:
        Establecimientos();
        Establecimientos(int idestablecimiento, const char *nombreestablecimiento, const char *direccionesta, const char*tipoesta);
        int getidestablecimiento();
        const char *getnombreestablecimiento();
        const char *getdireccionesta();
        const char *gettipoesta();
        void setidestablecimiento(int);
        void setnombreestablecimiento(const char*);
        void setdireccionesta(const char*);
        void settipoesta(const char*);
        std::string toString();

    protected:
        int _idestablecimiento;
        char _nombreestablecimiento[30];

    private:
        char _direccionesta[30];
        char _tipoesta[20];
};


