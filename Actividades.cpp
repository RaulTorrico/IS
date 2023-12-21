#include "Actividades.h"
#include <iostream>
void ActividadAcademica:: agregarActividadAlArchivo(const std::string& nombreArchivo) {
        // Construye una cadena con la información de la actividad
        std::string actividadInfo = nombreA_ + "," + descripcionA_ + "," + fechaInicio_ + "," + fechaFin_ + "," +
                                    contenido_ + "," + std::to_string(plazas_) + "," + std::to_string(precio_) + "," +
                                    std::to_string(aforo_) + "," + (asistencia_ ? "1" : "0");

        // Abre el archivo en modo de apertura al final
        std::ofstream archivo(nombreArchivo, std::ios::app);

        if (archivo.is_open()) {
            // Escribe la cadena en el archivo
            archivo << actividadInfo << std::endl;
            std::cout << "Actividad académica agregada correctamente." << std::endl;
            archivo.close(); // Cierra el archivo
        } else {
            std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        }
    }