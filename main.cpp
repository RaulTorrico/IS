#include <iostream>
#include <string>
#include "Usuario.h"  // Asegúrate de incluir correctamente los archivos de encabezado
#include "Actividades.h"

int main() {
    std::string usuario;
    std::string contraseña;
    std::string rol;
    int n;

    while (true) {
        std::cout << "******************************" << std::endl;
        std::cout << "1. Visualizar actividades     " << std::endl;
        std::cout << "2. Iniciar sesión             " << std::endl;
        std::cout << "3. Salir                      " << std::endl;
        std::cout << "******************************" << std::endl;
        std::cout << "Introduce uno de los numeros: ";
        std::cin >> n;

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

                rol=ObtenerRol(usuario);
                std::cout << rol;

                // Aquí puedes agregar la lógica para verificar las credenciales y asignar el rol
                // Supongo que estás utilizando algún tipo de lógica de autenticación.

                // Después de la autenticación, podrías asignar el rol al usuario
                // y realizar las acciones correspondientes según el rol.

                // Ejemplo de asignación de roles:
                /*if (usuario == "Alvaro") {
                    rol = 1;  // Director
                } else if (usuario == "Ismael") {
                    rol = 2;  // Usuario
                } else if (usuario == "Fernando") {
                    rol = 3;  // Organizador
                } else if (usuario == "Luis") {
                    rol = 4;  // Administrador
                } else {
                    rol = 0;  // Rol no reconocido
                }*/

                // Puedes utilizar el valor de 'rol' para realizar acciones específicas para cada rol.
                std::cout << "Iniciando sesión con rol: " << rol << std::endl;
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


