#include "Usuario.h"
#include <iostream>

/*void Usuario:: agregarUsuarioAlArchivo(const std::string& nombreArchivo)
    {
        // Construye una cadena con la información del usuario
        std::string usuarioInfo = std::to_string(id_) + "," + nombre_ + "," + correo_ + "," + password_ + "," + rol_;

        // Abre el archivo en modo de apertura al final
        std::ofstream archivo(nombreArchivo, std::ios::app);

        if (archivo.is_open())
        {
            // Escribe la cadena en el archivo
            archivo << usuarioInfo << std::endl;
            std::cout << "Usuario agregado correctamente." << std::endl;
            archivo.close(); // Cierra el archivo
        }
        else
        {
            std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        }
    }*/
bool VisualizarActividades(std::string nombreArchivo) {
    // Objeto de flujo de archivo
    std::ifstream archivo(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return false; // Indicar fallo
    }

    // Leer y mostrar el contenido del archivo línea por línea
    std::string linea;
    while (getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }

    // Verificar si ocurrió algún error durante la lectura
    if (archivo.bad()) {
        std::cerr << "Error durante la lectura del archivo " << nombreArchivo << std::endl;
        archivo.close();
        return false; // Indicar fallo
    }

    // Cerrar el archivo
    archivo.close();

    return true; // Indicar éxito
}

std::string ObtenerRol(std::string correo) {
    // Nombre del archivo de texto
    std::string nombreArchivo = "usuarios.txt";

    // Objeto de flujo de archivo
    std::ifstream archivo(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return ""; // Devolver cadena vacía en caso de error
    }

    std::string linea;
    while (getline(archivo, linea)) {
        // Buscar el correo en cada línea del archivo
        if (linea == correo) {
            // Leer la línea siguiente (contraseña)
            getline(archivo, linea);
            // Leer la línea siguiente (rol)
            getline(archivo, linea);
            archivo.close();
            return linea; // Devolver el rol
        }
    }

    // Usuario no encontrado
    archivo.close();
    return "";
}
