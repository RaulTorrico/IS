#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <string>

class Usuario {
private:
    std::string correo_;
    std::string password_;
    std::string rol_;
    std::string nombre_;

public:
    // Constructor de Usuario
    Usuario( std::string rol, std::string nombre = "", std::string correo = "", std::string password = "");

    // Método para agregar un usuario a un archivo
    void agregarUsuarioAlArchivo(const std::string& nombreArchivo);
    
};
bool VisualizarActividades(std::string nombreArchivo);
std::string  ObtenerRol(std::string usuario);
bool VerificarCredenciales(std::string usuario, std::string contraseña);
void preinscribirseActividad(std::string usuario, std::string nombreActividad);
#endif




