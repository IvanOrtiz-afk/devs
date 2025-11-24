#pragma once

class TipoAlmuerzo
{
public:
    TipoAlmuerzo(int idtipo);
    TipoAlmuerzo();
    int getidtipo();
    const char* getnombretipo();
    const char* getdesctipo();
    void setidtipo(int);
    void setnombretipo(int);
    void setdesctipo(int);
    std::string toString_tipo();

protected:
    char _nombretipo[20];
    int _idtipo;
    char _desctipo[20];
};

