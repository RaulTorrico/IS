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
        std::cout << "\n\n\n\n"<< std::endl;
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

    // Solicitar y validar el rol del usuario
    while (true) {
        std::cout << "Ingrese el rol del usuario (UsuarioRegistrado, Organizador, DirectorAcademico): ";
        std::cin >> rol;

        // Validar que el rol sea uno de los permitidos
        if (rol == "UsuarioRegistrado" || rol == "Organizador" || rol == "DirectorAcademico") {
            break;  // Salir del bucle si el rol es válido
        } else {
            std::cout << "Error: Rol no válido. Introduzca un rol correcto." << std::endl;
        }
    }

    std::cout << "Ingrese el nombre del usuario: ";
    std::cin >> nombre;

    // Construir la cadena con la información del usuario
    std::string usuarioInfo = correo + "\n" + password + "\n" + rol + "\n" + nombre + "\n";

    // Abrir el archivo en modo de apertura al final
    std::ofstream archivo("Usuarios.txt", std::ios::app);

    if (archivo.is_open()) {
        // Escribir la cadena en el archivo sin añadir líneas en blanco
        archivo << usuarioInfo;
        std::cout << "Usuario registrado correctamente." << std::endl;
        archivo.close(); // Cerrar el archivo
    } else {
        std::cerr << "Error al abrir el archivo Usuarios.txt" << std::endl;
    }
}

#include <iostream>
#include <fstream>
#include <string>

void eliminarUsuario(const std::string& correoUsuario) {
    // Nombre del archivo de usuarios
    std::string nombreArchivoUsuarios = "Usuarios.txt";

    // Nombre del archivo temporal para usuarios
    std::string archivoTemporalUsuarios = "Usuarios_temp.txt";

    // Objeto de flujo de archivo para lectura de usuarios
    std::ifstream archivoEntradaUsuarios(nombreArchivoUsuarios);

    // Verificar si el archivo de usuarios se abrió correctamente
    if (!archivoEntradaUsuarios.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivoUsuarios << std::endl;
        return;
    }

    // Crear un archivo temporal para almacenar los datos actualizados de usuarios
    std::ofstream archivoSalidaUsuarios(archivoTemporalUsuarios);

    // Variable para almacenar cada línea del archivo de usuarios
    std::string lineaUsuario;
    std::string correoEncontrado;

    // Variable para indicar si se encontró el usuario
    bool usuarioEncontrado = false;

    // Iterar sobre cada línea del archivo de usuarios
    while (getline(archivoEntradaUsuarios, correoEncontrado)) {
        // Verificar si la línea contiene el correo del usuario a eliminar
        if (correoEncontrado == correoUsuario) {
            // Se encontró el usuario, eliminar todas las líneas correspondientes a ese usuario
            usuarioEncontrado = true;
            getline(archivoEntradaUsuarios, lineaUsuario); // Saltar contraseña
            getline(archivoEntradaUsuarios, lineaUsuario); // Saltar rol
            getline(archivoEntradaUsuarios, lineaUsuario); // Saltar nombre
        } else {
            // Escribir la línea en el archivo temporal de usuarios (excepto si es la línea del usuario a eliminar)
            archivoSalidaUsuarios << correoEncontrado << std::endl;
            getline(archivoEntradaUsuarios, lineaUsuario); // Saltar contraseña
            archivoSalidaUsuarios << lineaUsuario << std::endl;
            getline(archivoEntradaUsuarios, lineaUsuario); // Saltar rol
            archivoSalidaUsuarios << lineaUsuario << std::endl;
            getline(archivoEntradaUsuarios, lineaUsuario); // Saltar nombre
            archivoSalidaUsuarios << lineaUsuario << std::endl;
        }
    }

    // Cerrar los archivos de usuarios
    archivoEntradaUsuarios.close();
    archivoSalidaUsuarios.close();

    // Verificar si se encontró el usuario antes de continuar
    if (!usuarioEncontrado) {
        std::cout << "El usuario con el correo " << correoUsuario << " no existe." << std::endl;
        return;
    }

    // Eliminar el archivo original de usuarios
    remove(nombreArchivoUsuarios.c_str());

    // Renombrar el archivo temporal de usuarios al nombre original
    if (rename(archivoTemporalUsuarios.c_str(), nombreArchivoUsuarios.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal de usuarios" << std::endl;
        return;
    }

    std::cout << "Usuario eliminado correctamente." << std::endl;
}

void imprimirListaPreinscritos() {
    // Nombre del archivo de lista de preinscritos
    std::string nombreArchivo = "listapreinscritos.txt";

    // Objeto de flujo de archivo
    std::ifstream archivo(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        // Imprimir cada línea
        std::cout << linea << std::endl;
    }

    // Cerrar el archivo
    archivo.close();
}

void eliminarUsuarioDePreinscritos(const std::string& correoUsuario) {
    // Nombre del archivo de lista de preinscritos
    std::string nombreArchivo = "listapreinscritos.txt";

    // Objeto de flujo de archivo
    std::ifstream archivoEntrada(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    // Verificar si el correo del usuario está en la lista de preinscritos
    bool usuarioEncontrado = false;
    std::string linea;
    while (getline(archivoEntrada, linea)) {
        if (linea.find(correoUsuario) != std::string::npos) {
            usuarioEncontrado = true;
            break;
        }
    }

    // Cerrar el archivo
    archivoEntrada.close();

    if (!usuarioEncontrado) {
        std::cout << "El usuario con correo " << correoUsuario << " no se encuentra en la lista de preinscritos." << std::endl;
        return;
    }

    // Crear un archivo temporal para almacenar las líneas que no deben eliminarse
    std::string nombreArchivoTemporal = "temporal.txt";
    std::ofstream archivoTemporal(nombreArchivoTemporal);

    if (!archivoTemporal.is_open()) {
        std::cerr << "Error al abrir el archivo temporal" << std::endl;
        return;
    }

    // Volver a abrir el archivo de entrada para leer desde el principio
    archivoEntrada.open(nombreArchivo);

    while (getline(archivoEntrada, linea)) {
        // Si la línea no contiene el correo de usuario a eliminar, escribirla en el archivo temporal
        if (linea.find(correoUsuario) == std::string::npos) {
            archivoTemporal << linea << std::endl;
        }
    }

    // Cerrar ambos archivos
    archivoEntrada.close();
    archivoTemporal.close();

    // Eliminar el archivo original
    if (remove(nombreArchivo.c_str()) != 0) {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    // Renombrar el archivo temporal al nombre original
    if (rename(nombreArchivoTemporal.c_str(), nombreArchivo.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
        return;
    }

    std::cout << "Usuario eliminado de la lista de preinscritos correctamente." << std::endl;
}



void pasarAInscrito() {
    // Solicitar el correo del usuario a pasar a inscrito
    std::string correoUsuarioAPasar;
    std::cout << "Ingrese el correo del usuario a pasar a inscrito: ";
    std::cin >> correoUsuarioAPasar;

    // Nombre del archivo de lista de preinscritos
    std::string nombreArchivoPreinscritos = "listapreinscritos.txt";

    // Nombre del archivo de lista de inscritos
    std::string nombreArchivoInscritos = "listainscritos.txt";

    // Objeto de flujo de archivo para lista de preinscritos
    std::ifstream archivoPreinscritos(nombreArchivoPreinscritos);

    // Verificar si el archivo se abrió correctamente
    if (!archivoPreinscritos.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivoPreinscritos << std::endl;
        return;
    }

    // Crear un archivo temporal para almacenar las líneas que no deben eliminarse
    std::string nombreArchivoTemporal = "temporal.txt";
    std::ofstream archivoTemporal(nombreArchivoTemporal);

    if (!archivoTemporal.is_open()) {
        std::cerr << "Error al abrir el archivo temporal" << std::endl;
        archivoPreinscritos.close();
        return;
    }
    
    std::ofstream archivoInscritos(nombreArchivoInscritos, std::ios::app);
    std::string linea;
    bool encontrado = false;
    while (getline(archivoPreinscritos, linea)) {
        // Si la línea contiene el correo de usuario a pasar
        if (linea.find(correoUsuarioAPasar) != std::string::npos) {
            // Mover la línea al archivo de lista de inscritos
            if (archivoInscritos.is_open()) {
                archivoInscritos << linea << std::endl;
                archivoInscritos.close();
                encontrado = true;
            } else {
                std::cerr << "Error al abrir el archivo " << nombreArchivoInscritos << std::endl;
            }
        } else {
            // Si la línea no contiene el correo de usuario a pasar, escribirla en el archivo temporal
            archivoTemporal << linea << std::endl;
        }
    }

    // Cerrar ambos archivos
    archivoPreinscritos.close();
    archivoTemporal.close();

    // Eliminar el archivo original
    if (remove(nombreArchivoPreinscritos.c_str()) != 0) {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    // Renombrar el archivo temporal al nombre original
    if (rename(nombreArchivoTemporal.c_str(), nombreArchivoPreinscritos.c_str()) != 0) {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
    }

    if (encontrado) {
        std::cout << "Usuario pasado a inscrito correctamente." << std::endl;
    } else {
        std::cout << "Usuario no encontrado en la lista de preinscritos." << std::endl;
    }
}




