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
    int plazas_;
    float precio_;

public:
    ActividadAcademica(std::string nombreA, std::string descripcionA, std::string fechaInicio, int plazas, float precio) {
        nombreA_ = nombreA;
        descripcionA_ = descripcionA;
        fechaInicio_ = fechaInicio;
        plazas_ = plazas;
        precio_ = precio;
    }
    // Método para agregar una actividad a un archivo
    void agregarActividadAlArchivo(std::string nombreArchivo);
};
void crearActividad();
void eliminarActividad();
#endif



