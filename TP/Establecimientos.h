#pragma once


class Establecimientos
{
    public:
        Establecimientos();
        int getidestablecimiento();
        char *getnombreestablecimiento();

    protected:
        int _idestablecimiento;
        char _nombreestablecimiento[30];

    private:
        char _direccionesta[30];
        char _tipoesta[20];
};


