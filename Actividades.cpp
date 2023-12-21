#include "Actividades.h"
#include <iostream>
void agregarActividadAlArchivo( std::string actividadInfo) {
    // Nombre del archivo de texto
    std::string nombreArchivo = "actividades.txt";
    // Abre el archivo en modo de apertura al final
    std::ofstream archivo(nombreArchivo, std::ios::app);

    if (archivo.is_open()) {
        // Escribe la información de la actividad en el archivo
        archivo << actividadInfo << std::endl;
        std::cout << "Actividad académica agregada correctamente al archivo." << std::endl;
        archivo.close(); // Cierra el archivo
    } else {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
    }
}

void crearActividad() {
    std::string nombreA, descripcionA, fechaInicio, contenido;
    int plazas;
    float precio;

    std::cout << "Ingrese el nombre de la actividad: ";
    std::cin >> nombreA;

    std::cout << "Ingrese la descripción de la actividad: ";
    std::cin >> descripcionA;

    std::cout << "Ingrese la fecha de inicio de la actividad: ";
    std::cin >> fechaInicio;

    std::cout << "Ingrese la cantidad de plazas disponibles: ";
    std::cin >> plazas;

    std::cout << "Ingrese el precio de la actividad: ";
    std::cin >> precio;

    // Crea la instancia de ActividadAcademica con la información ingresada
    ActividadAcademica nuevaActividad(nombreA, descripcionA, fechaInicio, plazas, precio);

    std::string actividadInfo = nombreA + "," + descripcionA + "," + fechaInicio + "," + std::to_string(plazas) + "," + std::to_string(precio);

    // Agrega la actividad al archivo
    agregarActividadAlArchivo(actividadInfo);
}

void eliminarActividad() {
    // Nombre del archivo de texto
    std::string nombreArchivo = "actividades.txt";

    // Nombre del archivo temporal
    std::string nombreArchivoTemp = "temp.txt";

    // Pide el nombre de la actividad a eliminar
    std::string nombreActividad;
    std::cout << "Ingrese el nombre de la actividad a eliminar: ";
    std::cin.ignore();  // Ignora el salto de línea pendiente en el búfer
    std::getline(std::cin, nombreActividad);

    // Abre el archivo original
    std::ifstream archivoEntrada(nombreArchivo);

    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    // Abre el archivo temporal
    std::ofstream archivoTemp(nombreArchivoTemp);

    if (!archivoTemp.is_open()) {
        std::cerr << "Error al abrir el archivo temporal " << nombreArchivoTemp << std::endl;
        archivoEntrada.close();
        return;
    }

    std::string linea;

    // Lee el archivo línea por línea
    while (getline(archivoEntrada, linea)) {
        // Busca el nombre de la actividad en la línea
        if (linea.find(nombreActividad) == std::string::npos) {
            // Si no se encuentra, escribe la línea en el archivo temporal
            archivoTemp << linea << std::endl;
        }
    }

    // Cierra ambos archivos
    archivoEntrada.close();
    archivoTemp.close();

    // Reemplaza el archivo original con el archivo temporal
    if (std::rename(nombreArchivoTemp.c_str(), nombreArchivo.c_str()) != 0) {
        std::cerr << "Error al reemplazar el archivo " << nombreArchivo << std::endl;
    } else {
        std::cout << "Actividad eliminada correctamente." << std::endl;
    }
}
