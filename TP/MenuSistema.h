#pragma once

class MenuSistema
{
  public:
    MenuSistema();
    MenuSistema(int rolUsuario);
    void run();
    
    void mostrarOpciones();
    void gestionarPlatos();
    void gestionarEstablecimientos();
    void gestionarComensales();
    void gestionarFacturas();
    void gestionarCC();
    void gestionarConsumos();
   
  private:
    int _cantidadOpciones;
    int _rolActual;
};
