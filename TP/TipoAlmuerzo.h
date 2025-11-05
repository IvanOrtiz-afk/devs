#pragma once

class TipoAlmuerzo
{
public:
    TipoAlmuerzo(int idtipo, const char* nombretipo, const char* desctipo);
    TipoAlmuerzo();
    int getidtipo();
    const char* getnombretipo();
    const char* getdesctipo();
    void setidtipo(int);
    void setnombretipo(const char*);
    void setdesctipo(const char*);
    std::string toString();

protected:
    char _nombretipo[30];

private:
    int _idtipo;
    char _desctipo[60];
};

