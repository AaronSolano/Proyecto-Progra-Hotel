#pragma once
#include "Librerias.h"
#include "Habitacion.h"

class ContenedorHabitaciones
{
private:
	vector<Habitacion> ListaHabitaciones;

public:

	void RegistrarHabitacion()
	{
		RecuperarDatos(); // Recuperar datos del archivo antes de registrar una nueva habitación.

        int numHabitacion, piso, cantPersonas;
        double precioXnoche;
        string descripcion;

        cout << "Ingrese el numero de habitacion: ";
        while (!(cin >> numHabitacion) || numHabitacion < 1) {
            cout << "Ingrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese el piso: ";
        while (!(cin >> piso) || piso < 1) {
            cout << " Ingrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese la descripcion: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, descripcion);
        while (descripcion.empty()) {
            cout << "Ingrese nuevamente: ";
            getline(cin, descripcion);
        }

        cout << "Ingrese la cantidad de personas: ";
        while (!(cin >> cantPersonas) || cantPersonas < 1) {
            cout << "Ingrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ingrese el precio por noche: ";
        while (!(cin >> precioXnoche) || precioXnoche < 1) {
            cout << "Ingrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        if (!verificarHabitacion(numHabitacion))
        {
			system("cls");
            Habitacion nuevaHabitacion(numHabitacion, piso, descripcion, cantPersonas, precioXnoche);
            ListaHabitaciones.push_back(nuevaHabitacion);
			cout << "---------------------------------------------------" << endl;
			cout << "Habitacion registrada con exito !!!" << endl;
            cout << "---------------------------------------------------" << endl;
        }
        else
        {
			system("cls");
            cout << "---------------------------------------------------" << endl;
            cout << "La habitacion ya existe !!!!" << endl;
            cout << "---------------------------------------------------" << endl;
        }

        // Mostrar la lista de habitaciones después de registrar una nueva
        for (int i = 0; i < ListaHabitaciones.size(); i++)
        {
            ListaHabitaciones[i].getDatosHabitacion();

        }
    }
	
    bool validarHabitacionReserva(int numHabit) //validar en el check in
    {
        bool sePuedeReservar = false;
        for (int i = 0; i < ListaHabitaciones.size(); i++)
        {
			if (ListaHabitaciones[i].getNumeroHabitacion() == numHabit)
			{
                if (ListaHabitaciones[i].getEstado() == 1)
                {
                    cout << "La habitacion se encuentra disponible " << endl;
                    sePuedeReservar = true;
                }
			}
		}
        if (!sePuedeReservar)
        {
			cout << "---------------------------------------------------" << endl;
			cout << "La habitacion no se encuentra disponible o no existe!!! " << endl;
			cout << "---------------------------------------------------" << endl;
		}
		return sePuedeReservar;
    }

	bool verificarHabitacion(int numHabitacion)
	{
		for (int i = 0; i < ListaHabitaciones.size(); i++)
		{
			if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion)
			{
				return true;
			}
		}
		return false;
	}


    void ModificarHabitacion(int numHabitacion)
    {

        int piso;
        string descripcion;
        int cantPersonas;
        double precioXnoche;

        if (ListaHabitaciones.empty())
        {
            cout << "--------------------------------------------" << endl;
			cout << " No hay Habitaciones Registradas" << endl;
			cout << "--------------------------------------------" << endl;
        }
        else
        {
            for (int i = 0; i < ListaHabitaciones.size(); i++)
            {
                if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion)
                {

                    cout << "Ingrese el piso: ";
                    while (!(cin >> piso) || piso < 1) {
                        cout << " Ingrese nuevamente: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cout << "Ingrese la descripcion: ";
                    cin.ignore(); // Limpiar el buffer
                    getline(cin, descripcion);
                    while (descripcion.empty()) {
                        cout << "Ingrese nuevamente: ";
                        getline(cin, descripcion);
                    }

                    cout << "Ingrese la cantidad de personas: ";
                    while (!(cin >> cantPersonas) || cantPersonas < 1) {
                        cout << "Ingrese nuevamente: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cout << "Ingrese el precio por noche: ";
                    while (!(cin >> precioXnoche) || precioXnoche < 1) {
                        cout << "Ingrese nuevamente: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    ListaHabitaciones[i].setActualizarHabitacion(piso, descripcion, cantPersonas, precioXnoche);
					cout << "---------------------------------------------------" << endl;
					cout << "Habitacion actualizada con exito!!!" << endl;
					cout << "---------------------------------------------------" << endl;
					ListaHabitaciones[i].getDatosHabitacion();
					break;
				}
                else
                {
                    cout << "--------------------------------------------" << endl;
                    cout << "Huesped no encontrado" << endl;
                    cout << "--------------------------------------------" << endl;
                }
            
           
            }

        }
        


    }

	void ConsultarHabitaciones()
	{
		system("cls");
        if (ListaHabitaciones.empty())
        {
            cout << "--------------------------------------------" << endl;
			cout << " No hay Habitaciones Registradas" << endl;
            cout << "--------------------------------------------" << endl;
        }
        else
        {
            int totalHabitaciones = ListaHabitaciones.size();
            int totalHabitacionesDisponibles = 0;

            cout << "------------|  Lista Habitaciones  |------------" << endl;
            for (int i = 0; i < ListaHabitaciones.size(); i++)
            {

                ListaHabitaciones[i].getDatosHabitacion();

                if (ListaHabitaciones[i].getEstado())
                {
                    totalHabitacionesDisponibles++;
                }
                
            }
            cout << "--------------------------------------------" << endl;
            cout << "Total de habitaciones: " << totalHabitaciones << endl;
            cout << "Total de habitaciones disponibles: " << totalHabitacionesDisponibles << endl;
            cout << "--------------------------------------------" << endl;
        }

	}

    void guardarContenedor() const 
{
        if (ListaHabitaciones.empty())
        {
			cout << "--------------------------------------------" << endl;
			cout << "No hay Habitaciones Registradas !!!" << endl;
			cout << "--------------------------------------------" << endl;
		}
        else
        {
            ofstream archivo("Habitaciones.txt");

            if (archivo.is_open()) {
                for (int i = 0; i < ListaHabitaciones.size(); i++) {
                    archivo << ListaHabitaciones[i].getNumeroHabitacion()
                        << "-" << ListaHabitaciones[i].getPiso()
                        << "-" << ListaHabitaciones[i].getDescripcion()
                        << "-" << ListaHabitaciones[i].getCantidadPersonas()
                        << "-" << ListaHabitaciones[i].getEstado()
                        << endl;
                }
                archivo.close();
                cout << "----------------------------------------------------------------" << endl;
                cout << "Lista de Habitaciones almacenados en el archivo correctamente..." << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }
    }

    void RecuperarDatos()
    {
       
        ListaHabitaciones.clear();

        ifstream archivo("Habitaciones.txt");
       if (archivo.is_open())
       {

           string linea;
           while (getline(archivo, linea))
           {
               stringstream ss(linea);
               string numHabitacion, piso, descripcion, cantPersonas, estado;

                getline(ss, numHabitacion, '-');

                getline(ss, piso, '-');

                getline(ss, descripcion, '-');

                getline(ss, cantPersonas, '-');

                getline(ss, estado, '-');

                 Habitacion nuevaHabitacion(stoi(numHabitacion), stoi(piso), descripcion, stoi(cantPersonas), stod(estado));

                 ListaHabitaciones.push_back(nuevaHabitacion);
           }
           archivo.close();
           cout << "----------------------------------------------------------------" << endl;
           cout << "Lista de Habitaciones cargados desde el archivo correctamente..." << endl;
           cout << "----------------------------------------------------------------" << endl;

       }
        
    }

    void ConsultarEstadoHabitacion()
    {

        int numHabitacion;
		cout << "Ingrese el numero de habitacion: ";
		while (!(cin >> numHabitacion) || numHabitacion < 1) {
			cout << "Ingrese nuevamente: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

        if (ListaHabitaciones.empty())
        {
            cout << "--------------------------------------------" << endl;
            cout << " No hay Habitaciones Registradas" << endl;
            cout << "--------------------------------------------" << endl;
            return;

        }
		else
		{
			for (int i = 0; i < ListaHabitaciones.size(); i++)
			{
				if (ListaHabitaciones[i].getNumeroHabitacion() == numHabitacion)
				{
					
					ListaHabitaciones[i].getDatosHabitacion();
					
					return;
				}
			}
			cout << "--------------------------------------------" << endl;
			cout << "La habitacion no existe !!!" << endl;
			cout << "--------------------------------------------" << endl;
		}
    }



	//menu de habitaciones

    void menuHabitaciones()
    {
        char opcion;

        do
        {
            system("cls");
            cout << "*********| Menu Habitaciones |**********" << endl;
            cout << "* 1- Registrar una habitación          *" << endl;
            cout << "* 2- Modificar una habitación          *" << endl;
            cout << "* 3- Consultar todas los Habitaciones  *" << endl;
            cout << "* 4- Guardar contenedor en archivo     *" << endl;
            cout << "* 5- Recuperar datos del archivo       *" << endl;
            cout << "* 6- Consultar estado de habitación    *" << endl;
			cout << "* 7- Regresar a menú principal         *" << endl;
            cout << "****************************************" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            switch (opcion)
            {
            case '1':
            {
				system("cls");
				RegistrarHabitacion();

                system("pause");
                break;
            }
            case '2':
            {
				system("cls");

				int numHabitacion;
				cout << "Ingrese el numero de habitacion a modificar: ";
				while (!(cin >> numHabitacion) || numHabitacion < 1) {
					cout << "Ingrese nuevamente: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				ModificarHabitacion(numHabitacion);

                system("pause");
                break;
            }
            case '3':
            {
				system("cls");
				ConsultarHabitaciones();

                system("pause");
                break;
            }
            case '4':
            {

				system("cls");
				guardarContenedor();

                system("pause");
                break;
            }
            case '5':
            {
				system("cls");
				RecuperarDatos();
                system("pause");
                break;
            }
            case '6':
            {
				system("cls");
				ConsultarEstadoHabitacion();

                system("pause");
                break;
            }
            case '7':
            {
				system("cls");
                cout << "-----------------------------------" << endl;
                cout << "Regresando al Menu principal......." << endl;
				cout << "-----------------------------------" << endl;
                break;
            }
            default:
            {

                cout << "Ingrese un valor valido !!" << endl;
                break;
            }

            }
        } while (opcion != '7');

    }
};