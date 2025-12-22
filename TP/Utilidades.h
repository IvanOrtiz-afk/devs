#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>



inline std::string entrada_cruda(const std::string& mensaje)
{
    std::string entrada;
    std::cout << mensaje << std::endl;
    if (std::cin.fail() || std::cin.peek() == '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::getline(std::cin, entrada);
    return entrada;
}

enum TipoEntrada
{
    NUMERO_ENTERO, TEXTO_NO_VACIO, NUMERO_FLOTANTE, TEXTO_SIN_NUMEROS
};

inline std::string entrada_valida(const std::string& mensaje, TipoEntrada tipo) ///Ahora usamos esto en ves de solo ignore y getline
{
    ///En discord te explico como funciona
    std::string entrada_str;
    // El bucle se repite hasta que se encuentra una entrada valida.
    while (true)
    {
        // Obtenemos la entrada como string
        entrada_str = entrada_cruda(mensaje);
        // Bloque switch para manejar la logica de validacion especifica.
        switch (tipo)
        {
        case NUMERO_ENTERO:
        {
            try // Se usa por si el programa tiene un error, y en ves de finalizar primero intenta esta solucion
            {
                // Intenta convertir el string a entero.
                // Si falla (por ejemplo, si el usuario ingresa "abc"), salta al 'catch'.
                std::stoi(entrada_str);
                // Si la conversion fue exitosa, la entrada es valida.
                return entrada_str;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "[ERROR] Entrada invalida. Por favor, ingrese un NUMERO ENTERO valido" << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "[ERROR] El numero ingresado es demasiado grande o pequenio. Intente con un valor razonable" << std::endl;
            }
            // Si hubo un error, el ciclo continua.
            break;
        }
        case TEXTO_NO_VACIO:
        {
            // 1. Verificamos si la cadena esta vacia
            if (entrada_str.empty())
            {
                std::cout << "[ERROR] La entrada no puede estar vacia. Intente de nuevo" << std::endl;
                break; // Continua el ciclo
            }
            // 2. Verificamos si la cadena contiene solo espacios en blanco
            // Utilizamos una copia temporal para eliminar espacios y verificar si queda algo mas.
            std::string temp = entrada_str;
            temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
            if (temp.empty())
            {
                std::cout << "[ERROR] La entrada no puede contener solo espacios en blanco. Ingrese texto valido" << std::endl;
                break; // Continua el ciclo
            }
            // Si paso ambas validaciones, la entrada es un texto valido.
            return entrada_str;
        }
        case NUMERO_FLOTANTE:
        {
            try
            {
                // Lo mismo que hicimos con NUMERO_ENTERO
                std::stof(entrada_str);
                return entrada_str;
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "[ERROR] Entrada invalida. Por favor, ingrese un NUMERO valido" << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << "[ERROR] El numero ingresado es demasiado grande o pequenio. Intente con un valor razonable" << std::endl;
            }
            break;
        }
        case TEXTO_SIN_NUMEROS:
        {

            if (entrada_str.empty())
            {
                std::cout << "[ERROR] La entrada no puede estar vacia." << std::endl;
                break;
            }

            if (entrada_str == "0") return entrada_str;


            std::string temp = entrada_str;
            temp.erase(std::remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
            if (temp.empty())
            {
                std::cout << "[ERROR] Ingrese texto valido, no solo espacios." << std::endl;
                break;
            }

            bool tieneNumeros = false;
            for (char c : entrada_str)
            {
                if (std::isdigit(c))
                {
                    tieneNumeros = true;
                    break;
                }
            }

            if (tieneNumeros)
            {
                std::cout << "[ERROR] El texto NO puede contener numeros, intente nuevamente";
                break;
            }
            return entrada_str;
        }
        default:
        {

            std::cout << "[ERROR INTERNO] Tipo de entrada no reconocido" << std::endl;
            return entrada_str;
        }
        }
    }
}
std::string entrada_valida(const std::string&, TipoEntrada);
std::string entrada_cruda(const std::string&);
