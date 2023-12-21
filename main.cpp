#include <iostream>
#include <string>
#include "Usuario.h"
#include "Actividades.h"

// Declaración de funciones

int main() {
    std::string usuario;
    std::string contraseña;
    std::string rol;
    int n;
    std::string nombreActividad;
    
    while (true) {
        std::cout << "******************************" << std::endl;
        std::cout << "1. Visualizar actividades     " << std::endl;
        std::cout << "2. Iniciar sesión             " << std::endl;
        std::cout << "3. Salir                      " << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << "Introduce uno de los numeros: ";
        std::cin >> n;
        getchar();
        switch (n) {
            case 1:
                std::cout << "Visualizando actividades..." << std::endl;
                VisualizarActividades("actividades.txt");
                break;

            case 2:
                std::cout << "Introduzca el nombre de usuario: ";
                std::cin >> usuario;
                std::cout << "Introduzca la contraseña: ";
                std::cin >> contraseña;

                if (VerificarCredenciales(usuario, contraseña)) {
                    // Si las credenciales son válidas, obtener el rol
                    rol = ObtenerRol(usuario);
                    std::cout << "Iniciando sesión con rol: " << rol << std::endl;
                } else {
                    // Mensaje si las credenciales son incorrectas
                    std::cout << "Usuario o contraseña incorrectos. Vuelve a intentar." << std::endl;
                }

                if (rol == "UsuarioRegistrado") {
                    int opcionUsuario;

                        while (true) {
                            // Menú para Usuario Registrado
                            std::cout << "******************************" << std::endl;
                            std::cout << "1. Visualizar actividades     " << std::endl;
                            std::cout << "2. Preinscribirse a actividad " << std::endl;
                            std::cout << "3. Salir                      " << std::endl;
                            std::cout << "******************************" << std::endl;
                            std::cout << "Introduce uno de los números: ";
                            std::cin >> opcionUsuario;

                            switch (opcionUsuario) {
                                case 1:
                                    std::cout << "Visualizando actividades..." << std::endl;
                                    VisualizarActividades("actividades.txt");
                                    break;

                                case 2:
                                    // Lógica para preinscribirse a una actividad
                                    std::cout << "Introduce el nombre de la actividad a la que deseas preinscribirte: ";
                                    std::cin >> nombreActividad;
                                    preinscribirseActividad(usuario, nombreActividad);
                                    break;

                                case 3:
                                    std::cout << "Saliendo del menú de Usuario Registrado" << std::endl;
                                    break;

                                default:
                                    std::cout << "Opción incorrecta, introduce una de las opciones que está en el menú" << std::endl;
                            }

                            if (opcionUsuario == 3) {
                                break;  // Salir del bucle si la opción es salir
                            }
                        }
                    }
                
                
                
                
                
                
                else if (rol == "Organizador") {
                    // Lógica para Organizador



                } 
                
                
                
                
                else if (rol == "DirectorAcademico") {
                    int opcionDirector;
                    getchar();
                    while (true) {
                        std::cout << "******************************" << std::endl;
                        std::cout << "1. Visualizar actividades     " << std::endl;
                        std::cout << "2. Crear actividad            " << std::endl;
                        std::cout << "3. Eliminar actividad         " << std::endl;
                        std::cout << "4. Salir                      " << std::endl;
                        std::cout << "******************************" << std::endl;
                        std::cout << "Introduce uno de los números: ";
                        std::cin >> opcionDirector;

                        switch (opcionDirector) {
                            case 1:
                                std::cout << "Visualizando actividades..." << std::endl;
                                VisualizarActividades("actividades.txt");
                                break;

                            case 2:
                                // Lógica para crear actividad
                                crearActividad();
                                break;

                            case 3:
                                // Lógica para eliminar actividad
                                eliminarActividad();
                                break;

                            case 4:
                                std::cout << "Saliendo del menú del Director Académico" << std::endl;
                                break;

                            default:
                                std::cout << "Opción incorrecta, introduce una de las opciones que está en el menú" << std::endl;
                        }

                        if (opcionDirector == 4) {
                            break;  // Salir del bucle si la opción es salir
                        }
                    }
                }

                break;

            case 3:
                std::cout << "Saliendo" << std::endl;
                return 0;

            default:
                std::cout << "Opcion incorrecta, introduce una de las opciones que está en el menú" << std::endl;
        }
    }

    return 0;
}

