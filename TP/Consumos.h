#pragma once

class Consumos
{
    public:
        Consumos();
        void setfecha(Fecha fecha);
        void setcliente(Comensal cliente);
        void settipo_mov(CuentaCorriente tipo_mov);
        void setplatoconsumido(Menues plato);
        void setvaloracion(int valoracion);
        Fecha getfecha();
        int getcliente();
        bool gettipo_mov();
        Menues getplato();
        int getvaloracion();

    protected:

    private:
        Fecha _fecha;
        Comensal _idcliente;
        CuentaCorriente _tipo_movimiento;
        Menues _plato;
        int _valoracion;
};


