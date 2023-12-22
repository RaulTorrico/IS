#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Usuario.h"
#include "mailing.h"
#include "Actividades.h"

// Declaración de funciones

int main() {
    std::string usuario;
    std::string contraseña;
    std::string rol;
    std::string correoUsuario;
    std::string correoPreinscritoAEliminar;
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
            system("clear");
                std::cout << "Visualizando actividades..." << std::endl;
                VisualizarActividades("actividades.txt");
                break;

            case 2:
            system("clear");
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
                    break;  
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
                                system("clear");
                                    std::cout << "Visualizando actividades..." << std::endl;
                                    VisualizarActividades("actividades.txt");
                                    break;

                                case 2:
                                system("clear");
                                    // Lógica para preinscribirse a una actividad
                                    std::cout << "Introduce el nombre de la actividad a la que deseas preinscribirte: ";
                                    std::cin >> nombreActividad;
                                    preinscribirseActividad(usuario, nombreActividad);
                                    break;

                                case 3:
                                system("clear");
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
        std::cout << "***********************************************" << std::endl;
        std::cout << "1. Visualizar actividades                      " << std::endl;
        std::cout << "2. Registrar usuario                           " << std::endl;
        std::cout << "3. Eliminar usuario                            " << std::endl;
        std::cout << "4. Ver lista de usuarios preinscritos          " << std::endl;
        std::cout << "5. Eliminar usuario de la lista de preinscritos" << std::endl;
        std::cout << "6. Pasar usuario a la lista de inscritos       " << std::endl;
        std::cout << "7. Mailing                                     " << std::endl;
        std::cout << "8. Crear actividad                             " << std::endl;
        std::cout << "9. Eliminar actividad                          " << std::endl;
        std::cout << "10. Salir                                      " << std::endl;
        std::cout << "***********************************************" << std::endl;
        std::cout << "Introduce uno de los números:                  ";
        std::cin >> opcionOrganizador;

        switch (opcionOrganizador) {
            case 1:
            system("clear");
                // Lógica para visualizar actividades
                VisualizarActividades("actividades.txt");
                break;

            case 2:
            system("clear");
                // Lógica para registrar usuario
                registrarUsuario();
                break;

            case 3:
            system("clear");
                // Lógica para eliminar usuario
                std::cout << "Ingrese el correo del usuario que desea eliminar: ";
                std::cin >> correoUsuario;

                // Llamar a la función para eliminar el usuario
                eliminarUsuario(correoUsuario);
                break;

            case 4:
            system("clear");
                // Lógica para ver lista de usuarios preinscritos
                imprimirListaPreinscritos();
                break;

            case 5:
            system("clear");
                // Lógica para eliminar usuario de la lista de preinscritos
                std::cout << "Ingrese el correo del usuario a eliminar de la lista de preinscritos: ";
                std::cin >> correoPreinscritoAEliminar;

                // Llamar a la función para eliminar el usuario de la lista de preinscritos
                eliminarUsuarioDePreinscritos(correoPreinscritoAEliminar);
                break;

            case 6:
            system("clear");
                // Lógica para pasar usuario a la lista de inscritos
                pasarAInscrito();
                break;

            case 7:
            system("clear");
                // Lógica para pasar usuario a la lista de inscritos
                Correo();
                break;
            
            case 8:
            system("clear");
                // Lógica para crear actividad
                crearActividad();
                break;

            case 9:
            system("clear");
                // Lógica para eliminar actividad
                eliminarActividad();
                break;

            case 10:
            system("clear");
                std::cout << "Saliendo del menú del Organizador" << std::endl;
                break;

            default:
                std::cout << "Opción incorrecta, introduce una de las opciones que está en el menú" << std::endl;
        }

        if (opcionOrganizador == 10) {
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
                            system("clear");
                                std::cout << "Visualizando actividades..." << std::endl;
                                VisualizarActividades("actividades.txt");
                                break;

                            case 2:
                            system("clear");
                                // Lógica para crear actividad
                                crearActividad();
                                break;

                            case 3:
                            system("clear");
                                // Lógica para eliminar actividad
                                eliminarActividad();
                                break;

                            case 4:
                            system("clear");
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
            system("clear");
            std::cout<<"Saliendo."<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            system("clear");
            std::cout<<"Saliendo.."<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            system("clear");
            std::cout<<"Saliendo..."<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            system("clear");
            std::cout<<"Saliendo."<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            system("clear");
            std::cout<<"Saliendo.."<<std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
                return 0;

            default:
                std::cout << "Opcion incorrecta, introduce una de las opciones que está en el menú" << std::endl;
        }
    }

    return 0;
}

