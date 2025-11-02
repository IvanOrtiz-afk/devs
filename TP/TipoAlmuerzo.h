#pragma once

class TipoAlmuerzo
{
public:
    TipoAlmuerzo();
    TipoAlmuerzo(int idtipo, const char* nombretipo, const char* desctipo);
    int getidtipo();
    const char* getnombretipo();
    const char* getdesctipo();
    void setidtipo(int);
    void setnombretipo(const char*);
    void setdesctipo(const char*);

protected:
    char _nombretipo[30];

private:
    int _idtipo;
    char _desctipo[60];
};

