#pragma once

class Consumos
{
    public:
        Consumos(Fecha fecha, Comensal idcliente, CuentaCorriente tipo_movimiento, Menues plato, int valoracion);
        void setfecha(Fecha fecha);
        void setcliente(Comensal cliente);
        void settipo_mov(CuentaCorriente tipo_mov);
        void setplatoconsumido(Menues plato);
        void setvaloracion(int valoracion);
        Fecha getfecha();
        int getcliente();
        bool gettipo_mov();
        const char* getplato();
        int getvaloracion();

    protected:

    private:
        Fecha _fecha;
        int _idcliente;
        bool _tipo_movimiento;
        char _plato[30];
        int _valoracion;
};


