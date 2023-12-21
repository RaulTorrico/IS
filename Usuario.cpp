#include "Usuario.h"
#include <iostream>

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
    std::string nombreArchivo = "Usuarios.txt";

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


bool VerificarCredenciales(std::string usuario, std::string contraseña) {
    // Nombre del archivo de texto
    std::string nombreArchivo = "Usuarios.txt";

    // Objeto de flujo de archivo
    std::ifstream archivo(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return false; // Devolver falso en caso de error
    }

    std::string correo;
    std::string pass;

    // Leer el archivo línea por línea
    while (getline(archivo, correo) && getline(archivo, pass)) {
        // Buscar el usuario por correo y verificar la contraseña
        if (correo == usuario && pass == contraseña) {
            archivo.close();
            return true;
        }
    }

    // Usuario no encontrado o credenciales incorrectas
    archivo.close();
    return false;
}

#include <iostream>
#include <fstream>
#include <sstream>

bool actividadExiste(const std::string& nombreActividad) {
    // Abre el archivo de actividades en modo lectura
    std::ifstream archivo("actividades.txt");

    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            // Compara el nombre de la actividad con la línea actual
            if (linea.find(nombreActividad) != std::string::npos) {
                archivo.close();
                return true;
            }
        }

        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo actividades.txt" << std::endl;
    }

    return false;
}

bool usuarioYaPreinscrito(const std::string& usuario, const std::string& nombreActividad) {
    // Abre el archivo de preinscritos en modo lectura
    std::ifstream archivo("listapreinscritos.txt");

    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            // Divide la línea en partes usando coma como delimitador
            std::istringstream iss(linea);
            std::string usuarioPreinscrito, actividadPreinscrita;
            if (getline(iss, usuarioPreinscrito, ',') && getline(iss, actividadPreinscrita, ',')) {
                // Compara el usuario y la actividad con los proporcionados
                if (usuarioPreinscrito == usuario && actividadPreinscrita == nombreActividad) {
                    archivo.close();
                    return true; // El usuario ya está preinscrito
                }
            }
        }

        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo listapreinscritos.txt" << std::endl;
    }

    return false; // El usuario no está preinscrito
}

void preinscribirseActividad( std::string usuario, std::string nombreActividad) {
    // Verifica que la actividad exista antes de preinscribirse
    if (actividadExiste(nombreActividad)) {
        // Verifica si el usuario ya está preinscrito
        if (usuarioYaPreinscrito(usuario, nombreActividad)) {
            std::cout << "Ya estás preinscrito en esta actividad." << std::endl;
        } else {
            // Abre el archivo en modo de apertura al final
            std::ofstream archivo("listapreinscritos.txt", std::ios::app);

            if (archivo.is_open()) {
                // Escribe la información en el archivo
                archivo << usuario << "," << nombreActividad << std::endl;
                std::cout << "Preinscripción realizada correctamente." << std::endl;
                archivo.close(); // Cierra el archivo
            } else {
                std::cerr << "Error al abrir el archivo listapreinscritos.txt" << std::endl;
            }
        }
    } else {
        std::cout << "La actividad ingresada no existe. Inténtalo de nuevo." << std::endl;
    }
}

void registrarUsuario() {
    std::string correo, password, rol, nombre;

    // Solicitar atributos del usuario
    std::cout << "Ingrese el correo del usuario: ";
    std::cin >> correo;

    std::cout << "Ingrese la contraseña del usuario: ";
    std::cin >> password;

    std::cout << "Ingrese el rol del usuario: ";
    std::cin >> rol;

    std::cout << "Ingrese el nombre del usuario: ";
    std::cin >> nombre;

    // Construir la cadena con la información del usuario
    std::string usuarioInfo = correo + "\n" + password + "\n" + rol + "\n" + nombre;

    // Abrir el archivo en modo de apertura al final
    std::ofstream archivo("Usuarios.txt", std::ios::app);

    if (archivo.is_open()) {
        // Escribir la cadena en el archivo
        archivo << usuarioInfo << std::endl;
        std::cout << "Usuario registrado correctamente." << std::endl;
        archivo.close(); // Cerrar el archivo
    } else {
        std::cerr << "Error al abrir el archivo Usuarios.txt" << std::endl;
    }
}
