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
        std::cout << "3. Registrarse                " << std::endl;
        std::cout << "4. Salir                      " << std::endl;
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
                    int opcionOrganizador;

    while (true) {
        std::cout << "******************************" << std::endl;
        std::cout << "1. Visualizar actividades     " << std::endl;
        std::cout << "2. Registrar usuario          " << std::endl;
        std::cout << "3. Eliminar usuario           " << std::endl;
        std::cout << "4. Ver lista de usuarios preinscritos" << std::endl;
        std::cout << "5. Eliminar usuario de la lista de preinscritos" << std::endl;
        std::cout << "6. Pasar usuario a la lista de inscritos" << std::endl;
        std::cout << "7. Salir                      " << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << "Introduce uno de los números: ";
        std::cin >> opcionOrganizador;

        switch (opcionOrganizador) {
            case 1:
                // Lógica para visualizar actividades
                VisualizarActividades("actividades.txt");
                break;

            case 2:
                // Lógica para registrar usuario
                registrarUsuario();
                break;

            case 3:
                // Lógica para eliminar usuario
                // Puedes llamar a una función que gestione la eliminación de usuarios
                // por ejemplo, eliminarUsuario();
                break;

            case 4:
                // Lógica para ver lista de usuarios preinscritos
                
                break;

            case 5:
                // Lógica para eliminar usuario de la lista de preinscritos
                
                break;

            case 6:
                // Lógica para pasar usuario a la lista de inscritos
                
                break;

            case 7:
                std::cout << "Saliendo del menú del Organizador" << std::endl;
                break;

            default:
                std::cout << "Opción incorrecta, introduce una de las opciones que está en el menú" << std::endl;
        }

        if (opcionOrganizador == 7) {
            break;  // Salir del bucle si la opción es salir
        }
    }

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
                registrarUsuario();
                break;
            case 4:
                std::cout << "Saliendo" << std::endl;
                return 0;

            default:
                std::cout << "Opcion incorrecta, introduce una de las opciones que está en el menú" << std::endl;
        }
    }

    return 0;
}

