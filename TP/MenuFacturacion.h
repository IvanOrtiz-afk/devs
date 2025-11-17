#pragma once
#include "Facturas.h"
#include "CC.h"
#include "Fecha.h"
#include "Menues.h"
#include "Comensales.h"
#include "Archivos.h"

class MenuFacturacion
{

public:
    MenuFacturacion();

private:

    void registrarVenta (Comensal comensal, Menues menu);
    Archivos<Factura> _archivoFacturas;
    Archivos<CuentaCorriente> _archivoCC;

};
