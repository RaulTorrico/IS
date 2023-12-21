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
    int id_;

public:
    // Constructor de Usuario
    Usuario(int id, std::string rol, std::string nombre = "", std::string correo = "", std::string password = "");

    // Método para agregar un usuario a un archivo
    void agregarUsuarioAlArchivo(const std::string& nombreArchivo);
    
};
bool VisualizarActividades(std::string nombreArchivo);
std::string  ObtenerRol(std::string usuario);
#endif




//     // Declaración de la clase derivada UsuarioRegistrado
//     class UsuarioRegistrado : public Usuario
// {
// public:
// };

// // Declaración de la clase derivada DirectorAcademico
// class DirectorAcademico : public Usuario
// {
// public:
// };

// // Declaración de la clase derivada Organizador
// class Organizador : public Usuario
// {
// public:
// };

// Función para iniciar sesión
// Usuario *iniciarSesion();

// void visualizar actividades();