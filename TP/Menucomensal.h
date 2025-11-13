#include "Submenu.h"
#include <string>

class Menucomensal : public Submenu
{

public:

protected:
    
    void cargar() override;    /// Override: hace referencia a que esta función está sobrescribiendo una función virtual que heredé de mi clase Padre
    void modificar() override;
    void eliminar() override;
    void mostrar() override;
    std::string getTitulo() override;
    
private:
   
 ///  _ComensalManager

};
