#include "Librerias.h"
#include "Contenedor Habitaciones.h"
#include "Contenedor Huespedes.h"
#include "Check-in.h"



int main()
{
	setlocale(LC_ALL, "spanish");
	system("color 0B");
	
	
	ContenedorHabitaciones contenedorHabitaciones;
	ContenedorHuespedes contenedorHuespedes;
	contenedorCheckIn checkin(contenedorHabitaciones, contenedorHuespedes);

    char opcion;

    do
    {
        system("cls");
        cout << "******** Menu principal ***********" << endl;
        cout << "* 1. - Gestionar Habitaciones -    *" << endl;
        cout << "* 2. - Gestionar Huespedes    -    *" << endl;
        cout << "* 3. - Gestionar Check-in     -    *" << endl;
        cout << "* 4. - Gestionar Check-Out    -    *" << endl;
        cout << "* 5. - Salir                  -    *" << endl;
        cout << "************************************" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case '1':
        {
			contenedorHabitaciones.menuHabitaciones();

            system("pause");
            break;
        }
        case '2':
        {
            /*cout << "   Pronto Estara disponible !!!!!" << endl;*/
			contenedorHuespedes.menuHuespedes();
         
            system("pause");
            break;
        }
        case '3':
        {
            checkin.menucheckIn();
            system("pause");
            break;
        }
        case '4':
        {
            cout << "   Pronto Estara disponible !!!!!" << endl;

            system("pause");
            break;
        }
        case '5':
        {
			
			char confirmacion;
			cout << "Desea salir del programa? (s/n): ";
			cin >> confirmacion;
			if (confirmacion == 's' || confirmacion == 'S')
			{
				system("cls");
				cout << "------------------------------------------------" << endl;
				cout << "Gracias por usar el programa, Vuelve Pronto !!! " << endl;
				cout << "------------------------------------------------" << endl;
				
			}
			else
			{
				opcion = '0';
			}

            break;
        }
        default:
        {
            cout << "Ingrese un valor valido !!" << endl;
            break;
        }

        }
    } while (opcion != '5');

}