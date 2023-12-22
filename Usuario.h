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
    Usuario(std::string correo, std::string password, std::string rol, std::string nombre)
{
    correo_ =correo;
    password_ =password;
    rol_ =rol;
    nombre_ =nombre;
}

    
};
bool VisualizarActividades(std::string nombreArchivo);
std::string  ObtenerRol(std::string usuario);
bool VerificarCredenciales(std::string usuario, std::string contraseña);
void preinscribirseActividad(std::string usuario, std::string nombreActividad);
void registrarUsuario();
void eliminarUsuario(const std::string& correoUsuario);
void imprimirListaPreinscritos();
void eliminarUsuarioDePreinscritos(const std::string& correoUsuario);
void pasarAInscrito();
#endif




