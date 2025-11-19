#pragma once

class MenuSistema
{
  public:
    MenuSistema(int rol);
    MenuSistema();
    void run(int rol);
    
    void mostrarOpciones();
    void gestionarPlatos();
    void gestionarEstablecimientos();
    void gestionarComensales();
    void gestionarFacturas();
    void gestionarCC();
    void gestionarConsumos();
    void gestionarUsuarios();

   
  private:
    int _cantidadOpciones;
    int _rolActual;
};
