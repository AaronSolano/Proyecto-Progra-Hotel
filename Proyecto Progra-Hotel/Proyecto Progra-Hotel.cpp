#include "Librerias.h"
#include "Contenedor Habitaciones.h"
#include "Contenedor Huespedes.h"
#include "Check-in.h"



int main()
{
	setlocale(LC_ALL, "spanish");
	///*system("color 09");*/
	
	
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
			    cout << "\033[1;33m Desea salir del programa? (s/n): \033[0m";
			    cin >> confirmacion;
			    if (confirmacion == 's' || confirmacion == 'S')
			    {
				    system("cls");
				    cout << "\033[1;33m------------------------------------------------" << endl;
				    cout << "Gracias por usar el programa, Vuelve Pronto !!! " << endl;
				    cout << "------------------------------------------------\033[0m" << endl;
				
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