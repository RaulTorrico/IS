#ifndef ACTIVIDADES_H
#define ACTIVIDADES_H

#include <fstream>
#include <iostream>
#include <list>
#include <string>

class ActividadAcademica {
private:
    std::string nombreA_;
    std::string descripcionA_;
    std::string fechaInicio_;
    std::string fechaFin_;
    std::string contenido_;
    int plazas_;
    float precio_;
    int aforo_;
    bool asistencia_;

public:
    // Constructor de ActividadAcademica similar al de Usuario
    ActividadAcademica(std::string nombreA, std::string descripcionA, std::string fechaInicio, std::string fechaFin,
                       std::string contenido, int plazas, float precio, int aforo, bool asistencia);

    // Método para agregar una actividad a un archivo
    void agregarActividadAlArchivo(const std::string& nombreArchivo);
};

#endif



