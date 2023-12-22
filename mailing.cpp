#include <iostream>
#include "mailing.h"

void Correo() {
    std::string destinatario;
    std::string concepto;
    std::string cuerpo;

    system("clear");
    std::cout << "SISTEMA DE COMUNICACIÓN DEL PROGRAMA" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "\n";

    std::cout << "Destinatarios (Separados por comas): ";
    getchar();
    std::getline(std::cin, destinatario);

    std::cout << "Asunto: ";
    getchar();
    std::getline(std::cin, concepto);

    std::cout << "Mensaje: " << std::endl;
    getchar();
    std::getline(std::cin, cuerpo);

    Mailing mailing = Mailing(destinatario, concepto, cuerpo);

    std::fstream correo;
    correo.open("copiadelmensaje.txt", std::ios::out);
    correo << "**********************************" << std::endl;
    correo << "*       COPIA DEL MENSAJE        *" << std::endl;
    correo << "**********************************" << std::endl;
    correo << "\n";
    correo << "------------------------" << std::endl;
    correo << "\n\n";
    correo << "Destinatario/s: " << mailing.GetDestinatario();;
    correo << "\n\n";
    correo << "Asunto: " << mailing.GetConcepto();
    correo << "\n\n";
    correo << "Cuerpo del mensaje:" << std::endl;
    correo << mailing.GetCuerpo();
    correo << "\n\n\n";

    system("clear");
    std::cout << "Mensaje enviado correctamente" << std::endl;
}

